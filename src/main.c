#include <pebble.h>
#include "main.h"

static Window *main_window;
static Layer *graphics_layer;

void graphics_layer_update_proc(Layer *l, GContext *ctx) {
	graphics_context_set_fill_color(ctx, GColorBlack);
	graphics_fill_rect(ctx, GRect(20, 20, 104, 128), 3, GCornersAll);
}

void main_window_load() {
	
	graphics_layer = layer_create(GRect(0, 0, 144, 168));
	layer_set_update_proc(graphics_layer, graphics_layer_update_proc);
	
	
	layer_add_child(window_get_root_layer(main_window), graphics_layer);
	
}

void main_window_unload() {
	
}

void init() {
	// Create main window
	main_window = window_create();

	// Set WindowHandlers
	window_set_window_handlers(main_window, (WindowHandlers) {
		.load = main_window_load,
		.unload = main_window_unload,
	});
	
	// Push to stack
	window_stack_push(main_window, true);
}

void deinit() {
	window_destroy(main_window);
}

int main() {
	init();
	app_event_loop();
	deinit();
}