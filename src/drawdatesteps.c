#include <pebble.h>
#include "drawdatesteps.h"

/*** DEFINE CONSTANTS ***/	

// constants used for frame size to avoid magic numbers
const int FRAME_WIDTH = 9;
const int FRAME_HEIGHT = 21;
const int FRAME_SPACE = 3;
const int FRAME_3_NARROW = 7;

/*** HELPER FUNCTIONS ***/	

// return horizontal offset for each character in the date
int calc_offset(int i) {
	int offset = i * (FRAME_WIDTH + FRAME_SPACE);
	if (i > 2) {
		offset -= FRAME_3_NARROW;
	}
	return offset;
}

/*** DRAWNG INDIVIDUAL ELEMENTS ***/	

// individual drawing elements, called by specific digit routines, to maximise code reuse

void draw_top_left_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(0 + i, 3), GPoint( 3 + i, 0));
}

void draw_top_right_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(5 + i, 0), GPoint(8 + i, 3));
}

void draw_second_left_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(0 + i, 6), GPoint( 3 + i, 9));
}

void draw_second_right_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(5 + i, 9), GPoint(8 + i, 6));
}

void draw_third_left_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(0 + i, 14), GPoint( 3 + i, 11));
}

void draw_third_right_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(5 + i, 11), GPoint(8 + i, 14));
}

void draw_bottom_left_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(0 + i, 17), GPoint(3 + i, 20));
}

void draw_bottom_right_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(5 + i, 20), GPoint(8 + i, 17));
}

void draw_left_line(GContext *ctx, int i, int top_pixel, int bottom_pixel) {
	graphics_draw_line(ctx, GPoint(0 + i, top_pixel), GPoint(0 + i, bottom_pixel));
}

void draw_mid_line(GContext *ctx, int i, int top_pixel, int bottom_pixel) {
	graphics_draw_line(ctx, GPoint(4 + i, top_pixel), GPoint(4 + i, bottom_pixel));
}

void draw_right_line(GContext *ctx, int i, int top_pixel, int bottom_pixel) {
	graphics_draw_line(ctx, GPoint(8 + i, top_pixel), GPoint(8 + i, bottom_pixel));
}

void draw_horiz_line(GContext *ctx, int i, int height, int left_pixel, int right_pixel) {
	graphics_draw_line(ctx, GPoint(left_pixel + i, height), GPoint(right_pixel + i, height));
}

/*** DRAWNG NUMBERS & LETTERS ***/	

// individual digit drawing functions

void draw_date_0(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 5, 9);
	draw_left_line(ctx, o, 11, 15);
	draw_right_line(ctx, o, 5, 9);
	draw_right_line(ctx, o, 11, 15);
}

void draw_date_1(GContext *ctx, int o) {
	draw_mid_line(ctx, o, 1, 9);
	draw_mid_line(ctx, o, 11, 19);
}

void draw_date_2(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_third_left_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
}

void draw_date_3(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_third_right_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
}

void draw_date_4(GContext *ctx, int o) {
	draw_left_line(ctx, o, 1, 4);
	draw_right_line(ctx, o, 1, 4);
	draw_second_left_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_right_line(ctx, o, 9, 13);
	draw_right_line(ctx, o, 15, 19);
}

void draw_date_5(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_second_left_diagonal(ctx, o);
	draw_third_right_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
}

void draw_date_6(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_third_left_diagonal(ctx, o);
	draw_third_right_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 6, 13);
}

void draw_date_7(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_right_line(ctx, o, 5, 11);
	draw_right_line(ctx, o, 13, 19);
}

void draw_date_8(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_second_left_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_third_left_diagonal(ctx, o);
	draw_third_right_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
}

void draw_date_9(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_second_left_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_right_line(ctx, o, 9, 15);
}

void draw_date_A(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_second_left_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 9, 13);
	draw_left_line(ctx, o, 15, 20);
	draw_right_line(ctx, o, 9, 13);
	draw_right_line(ctx, o, 15, 20);
}

void draw_date_B(GContext *ctx, int o) {
	draw_top_right_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_third_right_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 0, 9);
	draw_left_line(ctx, o, 11, 20);
	draw_horiz_line(ctx, o, 0, 2, 3);
	draw_horiz_line(ctx, o, 10, 2, 3);
	draw_horiz_line(ctx, o, 20, 2, 3);
}

void draw_date_C(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 5, 15);
}

void draw_date_D(GContext *ctx, int o) {
	draw_top_right_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 0, 9);
	draw_left_line(ctx, o, 11, 20);
	draw_horiz_line(ctx, o, 0, 2, 3);
	draw_horiz_line(ctx, o, 20, 2, 3);
	draw_right_line(ctx, o, 5, 9);
	draw_right_line(ctx, o, 11, 15);
}

void draw_date_E(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 5, 15);
	draw_horiz_line(ctx, o, 10, 2, 6);
}

void draw_date_F(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 5, 10);
	draw_left_line(ctx, o, 11, 20);
	draw_horiz_line(ctx, o, 10, 2, 6);
}

void draw_date_G(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_top_right_diagonal(ctx, o);
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 5, 15);
	draw_right_line(ctx, o, 10, 15);
	draw_horiz_line(ctx, o, 10, 5, 6);
}

void draw_date_J(GContext *ctx, int o) {
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_right_line(ctx, o, 0, 7);
	draw_right_line(ctx, o, 9, 15);
	draw_horiz_line(ctx, o, 0, 1, 6);
	
}

void draw_date_L(GContext *ctx, int o) {
	draw_left_line(ctx, o, 0, 9);
	draw_left_line(ctx, o, 11, 20);
	draw_horiz_line(ctx, o, 20, 2, 7);
}

void draw_date_M(GContext *ctx, int o) {
	draw_left_line(ctx, o, 0, 9);
	draw_left_line(ctx, o, 11, 20);
	draw_right_line(ctx, o, 0, 9);
	draw_right_line(ctx, o, 11, 20);
	graphics_draw_line(ctx, GPoint(2 + o, 2), GPoint(4 + o, 8));
	graphics_draw_line(ctx, GPoint(4 + o, 8), GPoint(6 + o, 2));
	
}

void draw_date_N(GContext *ctx, int o) {
	draw_left_line(ctx, o, 0, 9);
	draw_left_line(ctx, o, 11, 20);
	draw_right_line(ctx, o, 0, 9);
	draw_right_line(ctx, o, 11, 20);
	graphics_draw_line(ctx, GPoint(2 + o, 2), GPoint(6 + o, 18));
}

void draw_date_P(GContext *ctx, int o) {
	draw_top_right_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 0, 9);
	draw_left_line(ctx, o, 11, 20);
	draw_horiz_line(ctx, o, 0, 2, 3);
	draw_horiz_line(ctx, o, 10, 2, 3);
}

void draw_date_R(GContext *ctx, int o) {
	draw_top_right_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_third_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 0, 9);
	draw_left_line(ctx, o, 11, 20);
	draw_horiz_line(ctx, o, 0, 2, 3);
	draw_horiz_line(ctx, o, 10, 2, 3);
	draw_right_line(ctx, o, 16, 20);
}

void draw_date_S(GContext *ctx, int o) {
	draw_top_left_diagonal(ctx, o);
	draw_second_left_diagonal(ctx, o);
	draw_third_right_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_horiz_line(ctx, o, 0, 5, 7);
	draw_horiz_line(ctx, o, 20, 1, 3);
}

void draw_date_T(GContext *ctx, int o) {
	draw_horiz_line(ctx, o, 0, 0, 3);
	draw_horiz_line(ctx, o, 0, 5, 8);
	draw_mid_line(ctx, o, 2, 10);
	draw_mid_line(ctx, o, 12, 20);
}

void draw_date_U(GContext *ctx, int o) {
	draw_bottom_left_diagonal(ctx, o);
	draw_bottom_right_diagonal(ctx, o);
	draw_left_line(ctx, o, 0, 6);
	draw_left_line(ctx, o, 8, 14);
	draw_right_line(ctx, o, 0, 6);
	draw_right_line(ctx, o, 8, 14);
}

void draw_date_V(GContext *ctx, int o) {
	draw_left_line(ctx, o, 0, 5);
	draw_left_line(ctx, o, 7, 12);
	draw_right_line(ctx, o, 0, 5);
	draw_right_line(ctx, o, 7, 12);
	graphics_draw_line(ctx, GPoint(0 + o, 14), GPoint(4+o, 20));
	graphics_draw_line(ctx, GPoint(4 + o, 20), GPoint(8+o, 14));
}

void draw_date_Y(GContext *ctx, int o) {
	draw_left_line(ctx, o, 0, 4);
	draw_right_line(ctx, o, 0, 4);
	draw_second_left_diagonal(ctx, o);
	draw_second_right_diagonal(ctx, o);
	draw_mid_line(ctx, o, 12, 20);
}

/*** MAIN CALL ***/	

// main switching call, public
void drawdate(GContext *ctx, char *date_buffer) {
	
	for( int i = 0; i < 6; i++) {
		
		if ( i != 2) {  					// 3rd character is a blank space
			
			switch(date_buffer[i]) {
				case 48:
					draw_date_0(ctx, calc_offset(i));
					break;
				case 49:
					draw_date_1(ctx, calc_offset(i));
					break;
				case 50:
					draw_date_2(ctx, calc_offset(i));
					break;
				case 51:
					draw_date_3(ctx, calc_offset(i));
					break;
				case 52:
					draw_date_4(ctx, calc_offset(i));
					break;
				case 53:
					draw_date_5(ctx, calc_offset(i));
					break;
				case 54:
					draw_date_6(ctx, calc_offset(i));
					break;
				case 55:
					draw_date_7 (ctx, calc_offset(i));
					break;
				case 56:
					draw_date_8(ctx, calc_offset(i));
					break;
				case 57:
					draw_date_9(ctx, calc_offset(i));
					break;
				case 65:
					draw_date_A(ctx, calc_offset(i));
					break;
				case 66:
					draw_date_B(ctx, calc_offset(i));
					break;
				case 67:
					draw_date_C(ctx, calc_offset(i));
					break;
				case 68:
					draw_date_D(ctx, calc_offset(i));
					break;
				case 69:
					draw_date_E(ctx, calc_offset(i));
					break;
				case 70:
					draw_date_F(ctx, calc_offset(i));
					break;
				case 71:
					draw_date_G(ctx, calc_offset(i));
					break;
				case 74:
					draw_date_J(ctx, calc_offset(i));
					break;
				case 76:
					draw_date_L(ctx, calc_offset(i));
					break;
				case 77:
					draw_date_M(ctx, calc_offset(i));
					break;
				case 78:
					draw_date_N(ctx, calc_offset(i));
					break;
				case 79:
					draw_date_0(ctx, calc_offset(i));		// use zero
					break;
				case 80:
					draw_date_P(ctx, calc_offset(i));
					break;
				
				case 82:
					draw_date_R(ctx, calc_offset(i));
					break;
				case 83:
					draw_date_S(ctx, calc_offset(i));
					break;
				case 84:
					draw_date_T(ctx, calc_offset(i));
					break;
				case 85:
					draw_date_U(ctx, calc_offset(i));
					break;
				case 86:
					draw_date_V(ctx, calc_offset(i));
					break;
				case 89:
					draw_date_Y(ctx, calc_offset(i));
					break;
				default:
					draw_date_8(ctx, calc_offset(i));		// should never reach here, but if you do draw a figure 8
					break;
			}
		}		
	}
}

int calc_offset_for_steps(Layer *l, bool centred, int i, int num) {
	return i * (FRAME_WIDTH + FRAME_SPACE) + (centred ? ( layer_get_bounds(l).size.w - num * FRAME_WIDTH - (num-1) * FRAME_SPACE) / 2 : 0);
}

void drawsteps(Layer *l, GContext *ctx, char *steps_buffer, bool centred) {
	
	if( (int)strlen(steps_buffer) > 0) {
		for( int i = 0; i < (int)strlen(steps_buffer); i++) {

			int off = calc_offset_for_steps(l, centred, i, (int)strlen(steps_buffer));
			
			switch(steps_buffer[i]) {
				case 48:
					draw_date_0(ctx, off);
					break;
				case 49:
					draw_date_1(ctx, off);
					break;
				case 50:
					draw_date_2(ctx, off);
					break;
				case 51:
					draw_date_3(ctx, off);
					break;
				case 52:
					draw_date_4(ctx, off);
					break;
				case 53:
					draw_date_5(ctx, off);
					break;
				case 54:
					draw_date_6(ctx, off);
					break;
				case 55:
					draw_date_7(ctx, off);
					break;
				case 56:
					draw_date_8(ctx, off);
					break;
				case 57:
					draw_date_9(ctx, off);
					break;
				default:
					draw_date_8(ctx, off);		// should never reach here, but if you do draw a figure 8
					break;
			}
		}		
	}
}