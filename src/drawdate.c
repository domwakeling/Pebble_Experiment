#include <pebble.h>
#include "drawdate.h"

/* constants used for frame size to avoid magic numbers */

const int FRAME_WIDTH = 9;
const int FRAME_HEIGHT = 21;
const int FRAME_SPACE = 3;
const int FRAME_3_NARROW = 7;

/* return offset for each character */

int calc_offset(int i) {
	int offset = i * (FRAME_WIDTH + FRAME_SPACE);
	if (i > 2) {
		offset -= FRAME_3_NARROW;
	}
	return offset;
}

/* custom path drawing app; this differs from that in drawdigits.c because it allows for horizontal offset */

void custom_draw_gpathinfo_with_offset(GContext *ctx, GPathInfo *pathinfo, int i) {
	GPath *t_path = gpath_create(pathinfo);
	gpath_move_to(t_path, GPoint( calc_offset(i), 0 ));
	gpath_draw_filled(ctx, t_path);
	gpath_destroy(t_path);
}

/* "dummy" drawframe() function; this will draw a white frame and is used as the default in drawdate() */

void drawframe(GContext *ctx, int i) {
	GPathInfo TEMP_PATH =  {
		.num_points = 4,
		.points = (GPoint[]) {{0,0}, {FRAME_WIDTH - 1, 0}, {FRAME_WIDTH - 1, FRAME_HEIGHT - 1}, {0, FRAME_HEIGHT - 1}}
	};
	custom_draw_gpathinfo_with_offset( ctx, &TEMP_PATH, i);
}

/* individual drawing elements, called by specific digit routines, to maximise code reuse */

void draw_top_left_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(0 + calc_offset(i), 3), GPoint( 3 + calc_offset(i), 0));
}

void draw_top_right_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(5 + calc_offset(i), 0), GPoint(8 + calc_offset(i), 3));
}

void draw_second_left_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(0 + calc_offset(i), 6), GPoint( 3 + calc_offset(i), 9));
}

void draw_second_right_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(5 + calc_offset(i), 9), GPoint(8 + calc_offset(i), 6));
}

void draw_third_left_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(0 + calc_offset(i), 14), GPoint( 3 + calc_offset(i), 11));
}

void draw_third_right_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(5 + calc_offset(i), 11), GPoint(8 + calc_offset(i), 14));
}

void draw_bottom_left_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(0 + calc_offset(i), 17), GPoint(3 + calc_offset(i), 20));
}

void draw_bottom_right_diagonal(GContext *ctx, int i) {
	graphics_draw_line(ctx, GPoint(5 + calc_offset(i), 20), GPoint(8 + calc_offset(i), 17));
}

/* helper functions for drawing vertical lines */

void draw_left_line(GContext *ctx, int i, int top_pixel, int bottom_pixel) {
	graphics_draw_line(ctx, GPoint(0 + calc_offset(i), top_pixel), GPoint(0 + calc_offset(i), bottom_pixel));
}

void draw_mid_line(GContext *ctx, int i, int top_pixel, int bottom_pixel) {
	graphics_draw_line(ctx, GPoint(4 + calc_offset(i), top_pixel), GPoint(4 + calc_offset(i), bottom_pixel));
}

void draw_right_line(GContext *ctx, int i, int top_pixel, int bottom_pixel) {
	graphics_draw_line(ctx, GPoint(8 + calc_offset(i), top_pixel), GPoint(8 + calc_offset(i), bottom_pixel));
}

void draw_horiz_line(GContext *ctx, int i, int height, int left_pixel, int right_pixel) {
	graphics_draw_line(ctx, GPoint(left_pixel + calc_offset(i), height), GPoint(right_pixel + calc_offset(i), height));
}

/* individual digit drawing functions */

void draw_date_0(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 5, 9);
	draw_left_line(ctx, i, 11, 15);
	draw_right_line(ctx, i, 5, 9);
	draw_right_line(ctx, i, 11, 15);
}

void draw_date_1(GContext *ctx, int i) {
	draw_mid_line(ctx, i, 1, 9);
	draw_mid_line(ctx, i, 11, 19);
}

void draw_date_2(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_third_left_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
}

void draw_date_3(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
}

void draw_date_4(GContext *ctx, int i) {
	draw_left_line(ctx, i, 1, 4);
	draw_right_line(ctx, i, 1, 4);
	draw_second_left_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_right_line(ctx, i, 9, 13);
	draw_right_line(ctx, i, 15, 19);
}

void draw_date_5(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_second_left_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
}

void draw_date_6(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_third_left_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 6, 13);
}

void draw_date_7(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_right_line(ctx, i, 5, 11);
	draw_right_line(ctx, i, 13, 19);
}

void draw_date_8(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_second_left_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_third_left_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
}

void draw_date_9(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_second_left_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_right_line(ctx, i, 9, 15);
}

void draw_date_A(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_second_left_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 9, 13);
	draw_left_line(ctx, i, 15, 20);
	draw_right_line(ctx, i, 9, 13);
	draw_right_line(ctx, i, 15, 20);
}

void draw_date_B(GContext *ctx, int i) {
	draw_top_right_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 0, 9);
	draw_left_line(ctx, i, 11, 20);
	draw_horiz_line(ctx, i, 0, 2, 3);
	draw_horiz_line(ctx, i, 10, 2, 3);
	draw_horiz_line(ctx, i, 20, 2, 3);
}

void draw_date_C(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 5, 15);
}

void draw_date_D(GContext *ctx, int i) {
	draw_top_right_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 0, 9);
	draw_left_line(ctx, i, 11, 20);
	draw_horiz_line(ctx, i, 0, 2, 3);
	draw_horiz_line(ctx, i, 20, 2, 3);
	draw_right_line(ctx, i, 5, 9);
	draw_right_line(ctx, i, 11, 15);
}

void draw_date_E(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 5, 15);
	draw_horiz_line(ctx, i, 10, 2, 6);
}

void draw_date_F(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 5, 10);
	draw_left_line(ctx, i, 11, 20);
	draw_horiz_line(ctx, i, 10, 2, 6);
}

void draw_date_G(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 5, 15);
	draw_right_line(ctx, i, 10, 15);
	draw_horiz_line(ctx, i, 10, 5, 6);
}

void draw_date_H(GContext *ctx, int i) {
	draw_left_line(ctx, i, 0, 11);
	draw_left_line(ctx, i, 16, 20);
	draw_third_left_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_right_line(ctx, i, 0, 11);
	draw_right_line(ctx, i, 16, 20);
}

void draw_date_I(GContext *ctx, int i) {
	draw_horiz_line(ctx, i, 0, 0, 3);
	draw_horiz_line(ctx, i, 0, 5, 8);
	draw_horiz_line(ctx, i, 20, 0, 3);
	draw_horiz_line(ctx, i, 20, 5, 8);
	draw_mid_line(ctx, i, 2, 10);
	draw_mid_line(ctx, i, 12, 18);
}

void draw_date_J(GContext *ctx, int i) {
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_right_line(ctx, i, 0, 7);
	draw_right_line(ctx, i, 9, 15);
	draw_horiz_line(ctx, i, 0, 1, 6);
}

void draw_date_K(GContext *ctx, int i) {
	draw_left_line(ctx, i, 0, 9);
	draw_left_line(ctx, i, 11, 20);
	draw_horiz_line(ctx, i, 10, 2, 3);
	draw_second_right_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_right_line(ctx, i, 0, 4);
	draw_right_line(ctx, i, 16, 20);
}

void draw_date_L(GContext *ctx, int i) {
	draw_left_line(ctx, i, 0, 9);
	draw_left_line(ctx, i, 11, 20);
	draw_horiz_line(ctx, i, 20, 2, 7);
}

void draw_date_M(GContext *ctx, int i) {
	draw_left_line(ctx, i, 0, 9);
	draw_left_line(ctx, i, 11, 20);
	draw_right_line(ctx, i, 0, 9);
	draw_right_line(ctx, i, 11, 20);
	graphics_draw_line(ctx, GPoint(2 + calc_offset(i), 2), GPoint(4 + calc_offset(i), 8));
	graphics_draw_line(ctx, GPoint(4 + calc_offset(i), 8), GPoint(6 + calc_offset(i), 2));
}

void draw_date_N(GContext *ctx, int i) {
	draw_left_line(ctx, i, 0, 9);
	draw_left_line(ctx, i, 11, 20);
	draw_right_line(ctx, i, 0, 9);
	draw_right_line(ctx, i, 11, 20);
	graphics_draw_line(ctx, GPoint(2 + calc_offset(i), 2), GPoint(6 + calc_offset(i), 18));
}

void draw_date_P(GContext *ctx, int i) {
	draw_top_right_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 0, 9);
	draw_left_line(ctx, i, 11, 20);
	draw_horiz_line(ctx, i, 0, 2, 3);
	draw_horiz_line(ctx, i, 10, 2, 3);
}

void draw_date_Q(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_top_right_diagonal(ctx, i);
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 5, 9);
	draw_left_line(ctx, i, 11, 15);
	draw_right_line(ctx, i, 5, 11);
}

void draw_date_R(GContext *ctx, int i) {
	draw_top_right_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 0, 9);
	draw_left_line(ctx, i, 11, 20);
	draw_horiz_line(ctx, i, 0, 2, 3);
	draw_horiz_line(ctx, i, 10, 2, 3);
	draw_right_line(ctx, i, 16, 20);
}

void draw_date_S(GContext *ctx, int i) {
	draw_top_left_diagonal(ctx, i);
	draw_second_left_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_horiz_line(ctx, i, 0, 5, 7);
	draw_horiz_line(ctx, i, 20, 1, 3);
}

void draw_date_T(GContext *ctx, int i) {
	draw_horiz_line(ctx, i, 0, 0, 3);
	draw_horiz_line(ctx, i, 0, 5, 8);
	draw_mid_line(ctx, i, 2, 10);
	draw_mid_line(ctx, i, 12, 20);
}

void draw_date_U(GContext *ctx, int i) {
	draw_bottom_left_diagonal(ctx, i);
	draw_bottom_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 0, 6);
	draw_left_line(ctx, i, 8, 14);
	draw_right_line(ctx, i, 0, 6);
	draw_right_line(ctx, i, 8, 14);
}

void draw_date_V(GContext *ctx, int i) {
	draw_left_line(ctx, i, 0, 5);
	draw_left_line(ctx, i, 7, 12);
	draw_right_line(ctx, i, 0, 5);
	draw_right_line(ctx, i, 7, 12);
	graphics_draw_line(ctx, GPoint(0 + calc_offset(i), 14), GPoint(4+calc_offset(i), 20));
	graphics_draw_line(ctx, GPoint(4 + calc_offset(i), 20), GPoint(8+calc_offset(i), 14));
}

void draw_date_W(GContext *ctx, int i) {
	draw_left_line(ctx, i, 0, 9);
	draw_left_line(ctx, i, 11, 20);
	draw_right_line(ctx, i, 0, 9);
	draw_right_line(ctx, i, 11, 20);
	graphics_draw_line(ctx, GPoint(2 + calc_offset(i), 18), GPoint(4 + calc_offset(i), 12));
	graphics_draw_line(ctx, GPoint(4 + calc_offset(i), 12), GPoint(6 + calc_offset(i), 18));
}

void draw_date_X(GContext *ctx, int i) {
	draw_second_left_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_third_left_diagonal(ctx, i);
	draw_third_right_diagonal(ctx, i);
	draw_left_line(ctx, i, 0, 4);
	draw_right_line(ctx, i, 0, 4);
	draw_left_line(ctx, i, 16, 20);
	draw_right_line(ctx, i, 16, 20);
}

void draw_date_Y(GContext *ctx, int i) {
	draw_left_line(ctx, i, 0, 4);
	draw_right_line(ctx, i, 0, 4);
	draw_second_left_diagonal(ctx, i);
	draw_second_right_diagonal(ctx, i);
	draw_mid_line(ctx, i, 12, 20);
}

void draw_date_Z(GContext *ctx, int i) {
	draw_second_right_diagonal(ctx, i);
	draw_third_left_diagonal(ctx, i);
	draw_horiz_line(ctx, i, 20, 2, 8);
	draw_horiz_line(ctx, i, 0, 0, 6);
	draw_right_line(ctx, i, 0, 4);
	draw_left_line(ctx, i, 16, 20);
}

/* main switching call, public */

void drawdate(GContext *ctx, char *date_buffer) {
	
	for( int i = 0; i < 6; i++) {
		
		if ( i != 2) {  					// 3rd character is a blank space
			
			switch(date_buffer[i]) {
				
				case 48:
					draw_date_0(ctx,i);
					break;
				case 49:
					draw_date_1(ctx, i);
					break;
				case 50:
					draw_date_2(ctx, i);
					break;
				case 51:
					draw_date_3(ctx, i);
					break;
				case 52:
					draw_date_4(ctx, i);
					break;
				case 53:
					draw_date_5(ctx, i);
					break;
				case 54:
					draw_date_6(ctx, i);
					break;
				case 55:
					draw_date_7 (ctx, i);
					break;
				case 56:
					draw_date_8(ctx, i);
					break;
				case 57:
					draw_date_9(ctx, i);
					break;
				case 65:
					draw_date_A(ctx, i);
					break;
				case 66:
					draw_date_B(ctx, i);
					break;
				case 67:
					draw_date_C(ctx, i);
					break;
				case 68:
					draw_date_D(ctx, i);
					break;
				case 69:
					draw_date_E(ctx, i);
					break;
				case 70:
					draw_date_F(ctx, i);
					break;
				case 71:
					draw_date_G(ctx, i);
					break;
				case 72:
					draw_date_H(ctx, i);
					break;
				case 73:
					draw_date_I(ctx, i);
					break;
				case 74:
					draw_date_J(ctx, i);
					break;
				case 75:
					draw_date_K(ctx, i);
					break;
				case 76:
					draw_date_L(ctx, i);
					break;
				case 77:
					draw_date_M(ctx, i);
					break;
				case 78:
					draw_date_N(ctx, i);
					break;
				case 79:
					draw_date_0(ctx, i);		// use zero
					break;
				case 80:
					draw_date_P(ctx, i);
					break;
				case 81:
					draw_date_Q(ctx, i);
					break;
				case 82:
					draw_date_R(ctx, i);
					break;
				case 83:
					draw_date_S(ctx, i);
					break;
				case 84:
					draw_date_T(ctx, i);
					break;
				case 85:
					draw_date_U(ctx, i);
					break;
				case 86:
					draw_date_V(ctx, i);
					break;
				case 87:
					draw_date_W(ctx, i);
					break;
				case 88:
					draw_date_X(ctx, i);
					break;
				case 89:
					draw_date_Y(ctx, i);
					break;
				case 90:
					draw_date_Z(ctx, i);
					break;
				default:
					drawframe(ctx, i);
					break;
				
			}
			
		}
				
	}
	
}