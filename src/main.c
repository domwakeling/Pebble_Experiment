#include <pebble.h>
#include "drawdigits.h"
#include "drawdate.h"
	
#define KEY_SHOW_DATE 0;

const uint32_t STORAGE_DATE_VISIBLE = 1;

const int DATE_LENGTH = 7;
	
static Window *main_window;
static Layer *background_layer, *dots_layer;
static Layer *hours1_layer, *hours2_layer, *mins1_layer, *mins2_layer;
static Layer *date_layer;
static char time_buffer[] = "1234";
static char date_buffer[] = "30 SEP";

void background_update_proc(Layer *l, GContext *ctx) {
	// make background black
	graphics_context_set_fill_color(ctx, GColorBlack);
	graphics_fill_rect(ctx, GRect(0, 0, 144, 168), 0, GCornerNone);
}

void dots_update_proc(Layer *l, GContext *ctx) {
	// draw dots
	graphics_context_set_fill_color(ctx, GColorWhite);
	graphics_fill_rect(ctx, GRect(0, 26, 2, 5), 0, GCornerNone);
	graphics_fill_rect(ctx, GRect(0, 47, 2, 5), 0, GCornerNone);
}

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

void digits_update_proc(Layer *l, GContext *ctx) {
	// set context fill and stroke
	graphics_context_set_fill_color(ctx, GColorWhite);
	graphics_context_set_stroke_color(ctx, GColorWhite);

	// get the int from time_buffer char and draw
	int layer_ref = layer_ref_int(l);

	// get integer value; convert from ascii to numeric
	int val = (int)time_buffer[layer_ref] - 48;
	
	// call drawdigit() to actually draw the characters
	drawdigit(ctx, val);
}

void date_update_proc(Layer *l, GContext *ctx) {
	// set context fill and stroke
	graphics_context_set_fill_color(ctx, GColorWhite);
	graphics_context_set_stroke_color(ctx, GColorWhite);
	
	// check whether we are configured to draw date
	bool drawing_date = persist_read_bool(STORAGE_DATE_VISIBLE);
	
	// call drawdate() sending the date_buffer string if drawing_date is true
	if (drawing_date) {
		drawdate(ctx, date_buffer);
	}
}

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
}

void tick_handler(struct tm * time_time, TimeUnits units_changed) {
	update_time();
}

void main_window_load() {
	// Get a layer for the window to simplify adding layers
	Layer *window_layer = window_get_root_layer(main_window);
	
	// Create the layers
	background_layer = layer_create(GRect(0, 0, 144, 168));
	dots_layer = layer_create(GRect(71, 38, 2, 80));
	hours1_layer = layer_create(GRect(2, 34, 31, 88));
	hours2_layer = layer_create(GRect(36, 34, 31, 88));
	mins1_layer = layer_create(GRect(76, 34, 31, 88));
	mins2_layer = layer_create(GRect(111, 34, 31, 88));
	date_layer = layer_create(GRect(40,143,64,21));
	
	// Set update_proc for graphics layers
	layer_set_update_proc(hours1_layer, digits_update_proc);
	layer_set_update_proc(hours2_layer, digits_update_proc);
	layer_set_update_proc(mins1_layer, digits_update_proc);
	layer_set_update_proc(mins2_layer, digits_update_proc);
	layer_set_update_proc(background_layer, background_update_proc);
	layer_set_update_proc(dots_layer, dots_update_proc);
	layer_set_update_proc(date_layer, date_update_proc);
		
	// Add all layers to the window
	layer_add_child(window_layer, background_layer);
	layer_add_child(window_layer, dots_layer);
	layer_add_child(window_layer, hours1_layer);
	layer_add_child(window_layer, hours2_layer);
	layer_add_child(window_layer, mins1_layer);
	layer_add_child(window_layer, mins2_layer);
	layer_add_child(window_layer, date_layer);
	
	// Ensure correct time
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
}

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {
	
	// read first (and currently only) item from the dictionary
	Tuple *t = dict_read_first(iterator);
	
	char tempchar[4];
	snprintf(tempchar, sizeof(tempchar), "%s", t->value->cstring );
	
	APP_LOG(APP_LOG_LEVEL_DEBUG, "tempchar received as '%s'", tempchar);
	
	if (strcmp(tempchar,"on") == 0) {
		// store date visible true and refresh display
		APP_LOG(APP_LOG_LEVEL_INFO, "Received 'on', writing to storage");
		persist_write_bool(STORAGE_DATE_VISIBLE, true);
		update_time();
	} else if (strcmp(tempchar, "off") == 0){
		// store data visible false and refresh display
		APP_LOG(APP_LOG_LEVEL_INFO, "Received 'off', writing to storage");
		persist_write_bool(STORAGE_DATE_VISIBLE, false);
		update_time();
	} else {
		APP_LOG(APP_LOG_LEVEL_ERROR, "Error interpreting config - received value %s", tempchar);
	}
	
}

static void inbox_dropped_callback(AppMessageResult reason, void *context) {
	APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped");
}

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
	app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
	
	// Push to stack
	window_stack_push(main_window, true);
}

void deinit() {
	window_destroy(main_window);
	tick_timer_service_unsubscribe();
}

int main() {
	init();
	app_event_loop();
	deinit();
}