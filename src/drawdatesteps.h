#pragma once

void drawdate(GContext *ctx, char *date_buffer);

void drawsteps(Layer *l, GContext *ctx, char *steps_buffer, bool centred);

/* Public API to draw in the date & steps layers
 *
 * drawdate takes a GContext and date_buffer(2-digit date, space, 3-letter month)
 * drawsteps takes a Layer, GContext, steps_buffer (non-empty screen) and bool as to whether the layer is centred (otherwise left-align)
 *
 * All detail is private */