#include <pebble.h>
#include "drawdigits.h"
#include "drawdate.h"
#include "colourconversion.h"

/*** DEBUG MODE SWITCH ***/
//#define DEBUG

/*** KEY VALUES THROUGH DEFINES ***/	

// #define KEY_SHOW_DATE 0															// key values for communication with settings screen via Javascript
// #define KEY_SHOW_BLUETOOTH 1
// #define KEY_DIGIT_COLOUR 2

/*** KEY VALUES THROUGH DECLARATIONS ***/

const uint32_t STORAGE_DATE_VISIBLE = 1;						// key values for persistant storage
const uint32_t STORAGE_BLUETOOTH_VISIBLE = 2;
const uint32_t STORAGE_DIGIT_COLOUR_RED = 3;
const uint32_t STORAGE_DIGIT_COLOUR_BLUE = 4;
const uint32_t STORAGE_DIGIT_COLOUR_GREEN = 5;

/*** CONSTANTS THROUGH DEFINES - SIZE OF APP_MESSAGE ***/	
#define APP_OUTBOX 64
#define APP_INBOX 64

/*** CONSTANTS THROUGH DEFINES - DIGITS ETC ***/	

#define DIGIT_W 31																	// width of each digit
#define DIGIT_H 88																	// height of each digit
#define DIGIT_M 3																		// margin between each digit
#define DOTS_W 2																		// width of dots
#define DOTS_H 5																		// height of individual dots
#define DOTS_M 1																		// addl margin for dots
#define DOTS_V 16																		// vertical gap between dots

/*** CONSTANTS THROUGH DEFINES - BLUETOOTH LOGO ***/	

#define BT_HEIGHT 4																	// height of bluetooth triangles
#define BT_WIDTH 4																	// height of bluetooth triangles
#define BLUE_V_OFF_RD 5															// offset of bluetooth from top
#define BLUE_V_OFF_SQ 2
#define BLUE_H_OFF 4																// offset of bluetooth from edge, square

/*** CONSTANTS THROUGH DEFINES - DATE ***/	

#define DATE_W 64
#define DATE_H 21
#define DATE_V_OFF_RD 10
#define DATE_V_OFF_SQ 5

/*** CONSTANTS THROUGH DECLARATIONS ***/

const int DATE_LENGTH = 7;													// maximum length of date string, including return character

/*** VARIABLES & OBJECTS THROUGH DECLARATIONS ***/

bool bluetooth_connected = false;
static char time_buffer[] = "1234";
static char date_buffer[] = "30 SEP";

static Window *main_window;
static Layer *background_layer, *dots_layer;
static Layer *hours1_layer, *hours2_layer, *mins1_layer, *mins2_layer;
static Layer *date_layer;
static Layer *bluetooth_layer;

/*** HELPER FUNCTIONS ***/

// read persistent digit colours and provide as a GColor
GColor digit_colour() {
	
	#ifdef PBL_COLOR																	// if we're using a colour pebble
		
		// read the current persistant RGB (which will be 0,1,2,3) and convert to 0-255
		int redval = persist_read_to_255(persist_read_int(STORAGE_DIGIT_COLOUR_RED));
		int greenval = persist_read_to_255(persist_read_int(STORAGE_DIGIT_COLOUR_GREEN));
		int blueval = persist_read_to_255(persist_read_int(STORAGE_DIGIT_COLOUR_BLUE));
	
		// generate a temporary colour and return it
		GColor tempColour = GColorFromRGB(redval, greenval, blueval);
		return tempColour;
	
	#else
		return GColorWhite;														// return white if we're using a B&W pebble
	#endif
}													

int digit_origin_y() {
	GRect bounds = layer_get_frame(window_get_root_layer(main_window));
	return (bounds.size.h - DIGIT_H) / 2;
}

int digit_origin_x(int pos) {
	GRect bounds = layer_get_frame(window_get_root_layer(main_window));
	int width = 4 * DIGIT_W + 4 * DIGIT_M + DOTS_W + 2 * DOTS_M;
	int xPos = (bounds.size.w - width) / 2;
	if(pos == 0) return xPos;
	
	xPos = xPos + DIGIT_W + DIGIT_M;
	if(pos == 1) return xPos;
	
	xPos = xPos + DIGIT_W + 2 * DIGIT_M + DOTS_W + 2 * DOTS_M;
	if(pos == 2) return xPos;
	
	xPos = xPos + DIGIT_W + DIGIT_M;
	if(pos == 3) return xPos;
	
	return 0;
}

int dots_origin_x() {
	return digit_origin_x(1) + DIGIT_W + DIGIT_M + DOTS_M;
}

// return integer to represent the digit's layer reference
int layer_ref_int(Layer *l) {
	// get layer ref, used as lookup in time_buffer char
	if(l == hours1_layer) {
		return 0;
	} else if(l == hours2_layer) {
		return 1;
	} else if(l == mins1_layer) {
		return 2;
	} else {
		return 3;
	}
}

/*** UPDATE PROCS ***/	

void background_update_proc(Layer *l, GContext *ctx) {
	// make background black
	graphics_context_set_fill_color(ctx, GColorBlack);
	graphics_fill_rect(ctx, layer_get_frame(l), 0, GCornerNone);
}

void dots_update_proc(Layer *l, GContext *ctx) {
	// draw dots between digits
	graphics_context_set_fill_color(ctx, digit_colour());
	GRect bounds = layer_get_frame(l);
	int h1 = (bounds.size.h - 2 * DOTS_H - DOTS_V) / 2;
	int h2 = bounds.size.h - h1 - DOTS_H;
	graphics_fill_rect(ctx, GRect(0, h1, DOTS_W, DOTS_H), 0, GCornerNone);
	graphics_fill_rect(ctx, GRect(0, h2, DOTS_W, DOTS_H), 0, GCornerNone);
}

void digits_update_proc(Layer *l, GContext *ctx) {
	// set context fill and stroke
	graphics_context_set_fill_color(ctx, digit_colour());
	graphics_context_set_stroke_color(ctx, digit_colour());

	// get the int from time_buffer char and draw
	int layer_ref = layer_ref_int(l);

	// get integer value; convert from ascii to numeric
	int val = (int)time_buffer[layer_ref] - 48;
	
	// call drawdigit() to actually draw the characters
	drawdigit(ctx, val);
}

void date_update_proc(Layer *l, GContext *ctx) {
	// set context fill and stroke
	graphics_context_set_fill_color(ctx, digit_colour());
	graphics_context_set_stroke_color(ctx, digit_colour());
	
	// check whether we are configured to draw date
	bool drawing_date = persist_read_bool(STORAGE_DATE_VISIBLE);
	
	// call drawdate() sending the date_buffer string if drawing_date is true
	if (drawing_date) {
		drawdate(ctx, date_buffer);
	}
}

void bluetooth_update_proc(Layer *l, GContext *ctx) {
	// set context fill and stroke
	graphics_context_set_fill_color(ctx, digit_colour());
	graphics_context_set_stroke_color(ctx, digit_colour());
	
	// check whether we are configured to draw bluetooth
	bool drawing_bluetooth = persist_read_bool(STORAGE_BLUETOOTH_VISIBLE);
	
	if (drawing_bluetooth && bluetooth_connected) {
		graphics_draw_line(ctx, GPoint(BT_WIDTH, 0), GPoint(2 * BT_WIDTH, BT_HEIGHT));
		graphics_draw_line(ctx, GPoint(2 * BT_WIDTH, BT_HEIGHT), GPoint(BT_WIDTH, 2 * BT_HEIGHT));
		graphics_draw_line(ctx, GPoint(BT_WIDTH, 2 * BT_HEIGHT), GPoint(2 * BT_WIDTH, 3 * BT_HEIGHT));
		graphics_draw_line(ctx, GPoint(2 * BT_WIDTH, 3 * BT_HEIGHT), GPoint( BT_WIDTH, 4 * BT_HEIGHT));
		graphics_draw_line(ctx, GPoint(BT_WIDTH, 0), GPoint(BT_WIDTH, 4 * BT_HEIGHT));
		graphics_draw_line(ctx, GPoint(BT_WIDTH, 2 * BT_HEIGHT), GPoint(0 , BT_HEIGHT));
		graphics_draw_line(ctx, GPoint(BT_WIDTH, 2 * BT_HEIGHT), GPoint(0, 3 * BT_HEIGHT));
	}
}

/*****************************************************/
/************* DEAL WITH CHANGING TIME ***************/	
/*****************************************************/

/* called by tick_handler when time changes; update buffer and mark digits/date dirty */
void update_time() {
	// Get a tm struct
	time_t temp = time(NULL);
	struct tm *tick_time = localtime(&temp);
	
	// get the time into the time_buffer; respects 12/24 hours
	if (clock_is_24h_style()) {
		strftime(time_buffer, sizeof(time_buffer), "%H%M", tick_time);
	} else {
		strftime(time_buffer, sizeof(time_buffer), "%I%M", tick_time);
	}
	
	// get the date into the date_buffer
	strftime(date_buffer, DATE_LENGTH, "%d %b", tick_time);
	
	// convert to upper case
	u_int i = 0;
	for (i = 0; i < strlen(date_buffer) ; i++) {
		if( (date_buffer[i] >= 97) && (date_buffer[i] <= 122) ) {
			date_buffer[i] = date_buffer[i] - 32;
		} 
	}
	
	// mark the graphics layers dirty
	layer_mark_dirty(hours1_layer);
	layer_mark_dirty(hours2_layer);
	layer_mark_dirty(mins1_layer);
	layer_mark_dirty(mins2_layer);
	layer_mark_dirty(date_layer);
	layer_mark_dirty(bluetooth_layer);
}

/*** TICK HANDLER***/

void tick_handler(struct tm * time_time, TimeUnits units_changed) {
	update_time();
}

/*** WINDOW HANDLER CALLBACKS ***/	

static void setup_layers(Layer *window_layer) {
	
	GRect bounds = layer_get_frame(window_layer);
	int w1 = bounds.size.w;
	
	background_layer = layer_create(bounds);
	dots_layer = layer_create(GRect(dots_origin_x(), digit_origin_y(), DOTS_W, DIGIT_H));
	hours1_layer = layer_create(GRect(digit_origin_x(0), digit_origin_y(), DIGIT_W, DIGIT_H));
	hours2_layer = layer_create(GRect(digit_origin_x(1), digit_origin_y(), DIGIT_W, DIGIT_H));
	mins1_layer = layer_create(GRect(digit_origin_x(2), digit_origin_y(), DIGIT_W, DIGIT_H));
	mins2_layer = layer_create(GRect(digit_origin_x(3), digit_origin_y(), DIGIT_W, DIGIT_H));
	#ifdef PBL_ROUND
	bluetooth_layer = layer_create(GRect( (w1 - 2 * BT_WIDTH - 2)/2, BLUE_V_OFF_RD, 2 * BT_WIDTH + 2, 4 * BT_HEIGHT + 1));
	date_layer = layer_create(GRect((w1 - DATE_W)/2, bounds.size.h - DATE_H - DATE_V_OFF_RD, DATE_W, DATE_H));
	#else
	bluetooth_layer = layer_create(GRect(w1 - 2 * BT_WIDTH - 2 - BLUE_H_OFF, BLUE_V_OFF_SQ, 2 * BT_WIDTH + 2, 4 * BT_HEIGHT + 1));
	date_layer = layer_create(GRect((w1 - DATE_W)/2, bounds.size.h - DATE_H - DATE_V_OFF_SQ, DATE_W, DATE_H));
	#endif
	
	layer_set_update_proc(hours1_layer, digits_update_proc);
	layer_set_update_proc(hours2_layer, digits_update_proc);
	layer_set_update_proc(mins1_layer, digits_update_proc);
	layer_set_update_proc(mins2_layer, digits_update_proc);
	layer_set_update_proc(background_layer, background_update_proc);
	layer_set_update_proc(dots_layer, dots_update_proc);
	layer_set_update_proc(date_layer, date_update_proc);
	layer_set_update_proc(bluetooth_layer, bluetooth_update_proc);
	
	layer_add_child(window_layer, background_layer);
	layer_add_child(window_layer, dots_layer);
	layer_add_child(window_layer, hours1_layer);
	layer_add_child(window_layer, hours2_layer);
	layer_add_child(window_layer, mins1_layer);
	layer_add_child(window_layer, mins2_layer);
	layer_add_child(window_layer, date_layer);
	layer_add_child(window_layer, bluetooth_layer);
}

void main_window_load() {
	// Get a layer for the window to simplify adding layers
	Layer *window_layer = window_get_root_layer(main_window);
	
	// Create the layers
	setup_layers(window_layer);
	
	#ifdef DEBUG
	persist_write_bool(STORAGE_DATE_VISIBLE, true);
	persist_write_bool(STORAGE_BLUETOOTH_VISIBLE, true);
	bluetooth_connected = bluetooth_connection_service_peek();
	#endif
	
	update_time();
}

void main_window_unload() {
	// Remove all the layers
	layer_destroy(hours1_layer);
	layer_destroy(hours2_layer);
	layer_destroy(mins1_layer);
	layer_destroy(mins2_layer);
	layer_destroy(background_layer);
	layer_destroy(dots_layer);
	layer_destroy(date_layer);
	layer_destroy(bluetooth_layer);
}

/*** BLUETOOTH HANDLER ***/

void bt_handler(bool connected) {
	// whatever the connected state is, pass it to bluetooth_connected and update time to reflect on screen
	bluetooth_connected = connected;
	update_time();
}

/*** COMMUNICATION HANDLER CALLBACKS ***/	

// inbox received callback, deal with successful receipt of message from phone
static void inbox_received_callback(DictionaryIterator *iterator, void *context) {
	// before we do anything else, make necessary buffers
	char date_on_off_buffer[4];
	char bluetooth_on_off_buffer[4];
	#ifdef PBL_COLOR
		char colour_hex_buffer[8];
		char *colour_hex_buffer_pointer;
		colour_hex_buffer_pointer = colour_hex_buffer;
	#endif
	
	Tuple *tempDate = dict_find(iterator, MESSAGE_KEY_SHOW_DATE);
	// 'if' wrapper to ensure we've got a valid tuple
	if (tempDate) {
		// get the value ("on" or "off") and log it				
		snprintf(date_on_off_buffer, sizeof(date_on_off_buffer), "%s", tempDate->value->cstring );
		APP_LOG(APP_LOG_LEVEL_INFO, "Date tempchar received as '%s'", date_on_off_buffer);

		// change date-visible as appropriate
		if (strcmp(date_on_off_buffer,"on") == 0) {
			// store date visible true and refresh display
			APP_LOG(APP_LOG_LEVEL_INFO, "Received date 'on', writing to storage");
			persist_write_bool(STORAGE_DATE_VISIBLE, true);
			update_time();
		} else if (strcmp(date_on_off_buffer, "off") == 0){
			// store data visible false and refresh display
			APP_LOG(APP_LOG_LEVEL_INFO, "Received date 'off', writing to storage");
			persist_write_bool(STORAGE_DATE_VISIBLE, false);
			update_time();
		} else {
			APP_LOG(APP_LOG_LEVEL_ERROR, "Error interpreting config - received value %s for dateshowing", date_on_off_buffer);
		}
	}
	
	Tuple *tempBlue = dict_find(iterator, MESSAGE_KEY_SHOW_BLUETOOTH);
	// 'if' wrapper to ensure we've got a valid tuple
	if (tempBlue) {
		// get the value ("on" or "off") and log it				
		snprintf(bluetooth_on_off_buffer, sizeof(bluetooth_on_off_buffer), "%s", tempBlue->value->cstring );
		APP_LOG(APP_LOG_LEVEL_INFO, "Bluetooth tempchar received as '%s'", bluetooth_on_off_buffer);

		// change bluetooth-visible as appropriate
		if (strcmp(bluetooth_on_off_buffer,"on") == 0) {
			// store bluetooth visible true
			APP_LOG(APP_LOG_LEVEL_INFO, "Received bluetooth 'on', writing to storage");
			persist_write_bool(STORAGE_BLUETOOTH_VISIBLE, true);
			// subscribe to the service, get current status
			bluetooth_connection_service_subscribe(bt_handler);
			APP_LOG(APP_LOG_LEVEL_INFO, "Subscribed to blueooth connection");
			bluetooth_connected = bluetooth_connection_service_peek();
			// update the display
			update_time();
		} else if (strcmp(bluetooth_on_off_buffer, "off") == 0){
			// store bluetooth visible false
			APP_LOG(APP_LOG_LEVEL_INFO, "Received bluetooth 'off', writing to storage");
			persist_write_bool(STORAGE_BLUETOOTH_VISIBLE, false);
			// unsubscribe
			bluetooth_connection_service_unsubscribe();
			update_time();
		} else {
			APP_LOG(APP_LOG_LEVEL_ERROR, "Error interpreting config - received value %s for bluetoothshowing", bluetooth_on_off_buffer);
		}
	}
	
	#ifdef PBL_COLOR
	Tuple *tempColour = dict_find(iterator, MESSAGE_KEY_DIGIT_COLOUR);
	// 'if' wrapper to ensure we've got a valid tuple
	if (tempColour) {
					snprintf(colour_hex_buffer, sizeof(colour_hex_buffer), "%s", tempColour->value->cstring );
					APP_LOG(APP_LOG_LEVEL_INFO, "Received hex code %s, writing to storage", colour_hex_buffer);
					write_colour_to_persist(colour_hex_buffer_pointer, STORAGE_DIGIT_COLOUR_RED, STORAGE_DIGIT_COLOUR_GREEN, STORAGE_DIGIT_COLOUR_BLUE);
					update_time();
	}
	#endif
}

// inbox dropped callback - logs a message that there's been an error
static void inbox_dropped_callback(AppMessageResult reason, void *context) {
	APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped");
}

/*** INIT, DEINIT & MAIN ***/	

void init() {
	// Create main window
	main_window = window_create();
	
	// Set WindowHandlers
	window_set_window_handlers(main_window, (WindowHandlers) {
		.load = main_window_load,
		.unload = main_window_unload,
	});
	
	// Subscribe to tick_timer
	tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
	
	// register appMessage handlers
	app_message_register_inbox_received(inbox_received_callback);
	app_message_register_inbox_dropped(inbox_dropped_callback);
	
	// open AppMessage
	//app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());		// frowned upon
	app_message_open(APP_INBOX, APP_OUTBOX);
	
	// check whether bluetooth display is active and if so set it up
	if(persist_read_bool(STORAGE_BLUETOOTH_VISIBLE)) {
		bluetooth_connection_service_subscribe(bt_handler);
		bluetooth_connected = bluetooth_connection_service_peek();
	}
	
	// Push to stack
	window_stack_push(main_window, true);
}

void deinit() {
	window_destroy(main_window);
	tick_timer_service_unsubscribe();
	bluetooth_connection_service_unsubscribe();
}

int main() {
	init();
	app_event_loop();
	deinit();
}