#include <pebble.h>
#include "drawdigits.h"

/* Global function passing in GPathInfo */

void custom_draw_gpathinfo(GContext *ctx, GPathInfo *pathinfo) {
	GPath *t_path = gpath_create(pathinfo);
	gpath_draw_filled(ctx, t_path);
	gpath_destroy(t_path);
}

/* Individual functions defining GPathInfo and passng to the custom_draw_gpathinfo */

void draw_left_1(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,0}, {4,0}, {4,3}, {0,7}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_2(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,11}, {4,7}, {4,15}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_3(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,15}, {4,19}, {4,24}, {0,28}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,32}, {4,28}, {4,36}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_5(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,36}, {4,40}, {4,46}, {0,50}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_6(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,54}, {4,50}, {4,58}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_7(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,58}, {4,62}, {4,66}, {0,70}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_8(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,74}, {4,70}, {4,78}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_9(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,78}, {4,82}, {4,85}, {0,85}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_1(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,0}, {26,0}, {26,3}, {30,7}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_2(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,11}, {26,7}, {26,15}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_3(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,15}, {26,19}, {26,24}, {30,28}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,32}, {26,28}, {26,36}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_5(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,36}, {26,40}, {26,46}, {30,50}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_6(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,54}, {26,50}, {26,58}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_7(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,58}, {26,62}, {26,66}, {30,70}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_8(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,74}, {26,70}, {26,78}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_9(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,78}, {26,82}, {26,85}, {30,85}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_diag_1(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{0,11}, {11,0}, {13,0}, {13,4}, {3,14}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_left_diag_2(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,32}, {3,29}, {12,38}, {9,41}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_left_diag_3(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,54}, {9,45}, {11,48}, {3,57}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_left_diag_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{0,74}, {3,71}, {13,81}, {13,85}, {11,85}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_right_diag_1(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{30,11}, {19,0}, {17,0}, {17,4}, {27,14}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_right_diag_2(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,32}, {27,29}, {18,38}, {21,41}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_right_diag_3(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,54}, {21,45}, {19,48}, {27,57}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_right_diag_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{30,74}, {27,71}, {17,81}, {17,85}, {19,85}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_rhombus(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{12,43}, {15,40}, {18,43}, {15,46}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

/* *** Functions to draw numbers from paths *** */

void draw_zero(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_left_diag_4(ctx);
	draw_left_3(ctx);
	draw_left_4(ctx);
	draw_left_5(ctx);
	draw_left_6(ctx);
	draw_left_7(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_4(ctx);
	draw_right_3(ctx);
	draw_right_4(ctx);
	draw_right_5(ctx);
	draw_right_6(ctx);
	draw_right_7(ctx);
}

void draw_one(GContext *ctx) {
	draw_right_1(ctx);
	draw_right_2(ctx);
	draw_right_3(ctx);
	draw_right_4(ctx);
	draw_right_5(ctx);
	draw_right_6(ctx);
	draw_right_7(ctx);
	draw_right_8(ctx);
	draw_right_9(ctx);
}
															 
void draw_two(GContext *ctx) {
	draw_left_diag_1(ctx);
	//draw_left_diag_2(ctx);
	draw_left_diag_3(ctx);
	draw_left_diag_4(ctx);
	//draw_left_1(ctx);
	//draw_left_2(ctx);
	draw_left_3(ctx);
	//draw_left_4(ctx);
	//draw_left_5(ctx);
	//draw_left_6(ctx);
	draw_left_7(ctx);
	//draw_left_8(ctx);
	//draw_left_9(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_2(ctx);
	//draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	//draw_right_1(ctx);
	//draw_right_2(ctx);
	draw_right_3(ctx);
	//draw_right_4(ctx);
	//draw_right_5(ctx);
	//draw_right_6(ctx);
	draw_right_7(ctx);
	//draw_right_8(ctx);
	//draw_right_9(ctx);
	draw_rhombus(ctx);
}

void draw_three(GContext *ctx) {
	draw_left_diag_1(ctx);
	//draw_left_diag_2(ctx);
	//draw_left_diag_3(ctx);
	draw_left_diag_4(ctx);
	//draw_left_1(ctx);
	//draw_left_2(ctx);
	//draw_left_3(ctx);
	//draw_left_4(ctx);
	//draw_left_5(ctx);
	//draw_left_6(ctx);
	//draw_left_7(ctx);
	//draw_left_8(ctx);
	//draw_left_9(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_2(ctx);
	draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	//draw_right_1(ctx);
	//draw_right_2(ctx);
	draw_right_3(ctx);
	//draw_right_4(ctx);
	//draw_right_5(ctx);
	//draw_right_6(ctx);
	draw_right_7(ctx);
	//draw_right_8(ctx);
	//draw_right_9(ctx);
	draw_rhombus(ctx);
}

void draw_four(GContext *ctx) {
	//draw_left_diag_1(ctx);
	draw_left_diag_2(ctx);
	//draw_left_diag_3(ctx);
	//draw_left_diag_4(ctx);
	draw_left_1(ctx);
	draw_left_2(ctx);
	draw_left_3(ctx);
	//draw_left_4(ctx);
	//draw_left_5(ctx);
	//draw_left_6(ctx);
	//draw_left_7(ctx);
	//draw_left_8(ctx);
	//draw_left_9(ctx);
	//draw_right_diag_1(ctx);
	draw_right_diag_2(ctx);
	//draw_right_diag_3(ctx);
	//draw_right_diag_4(ctx);
	draw_right_1(ctx);
	draw_right_2(ctx);
	draw_right_3(ctx);
	draw_right_4(ctx);
	draw_right_5(ctx);
	draw_right_6(ctx);
	draw_right_7(ctx);
	draw_right_8(ctx);
	draw_right_9(ctx);
	draw_rhombus(ctx);
}

void draw_five(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_left_diag_2(ctx);
	//draw_left_diag_3(ctx);
	draw_left_diag_4(ctx);
	//draw_left_1(ctx);
	//draw_left_2(ctx);
	draw_left_3(ctx);
	//draw_left_4(ctx);
	//draw_left_5(ctx);
	//draw_left_6(ctx);
	draw_left_7(ctx);
	//draw_left_8(ctx);
	//draw_left_9(ctx);
	draw_right_diag_1(ctx);
	//draw_right_diag_2(ctx);
	draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	//draw_right_1(ctx);
	//draw_right_2(ctx);
	draw_right_3(ctx);
	//draw_right_4(ctx);
	//draw_right_5(ctx);
	//draw_right_6(ctx);
	draw_right_7(ctx);
	//draw_right_8(ctx);
	//draw_right_9(ctx);
	draw_rhombus(ctx);
}

void draw_six(GContext *ctx) {
	draw_left_diag_1(ctx);
	//draw_left_diag_2(ctx);
	draw_left_diag_3(ctx);
	draw_left_diag_4(ctx);
	//draw_left_1(ctx);
	//draw_left_2(ctx);
	draw_left_3(ctx);
	draw_left_4(ctx);
	draw_left_5(ctx);
	draw_left_6(ctx);
	draw_left_7(ctx);
	//draw_left_8(ctx);
	//draw_left_9(ctx);
	draw_right_diag_1(ctx);
	//draw_right_diag_2(ctx);
	draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	//draw_right_1(ctx);
	//draw_right_2(ctx);
	//draw_right_3(ctx);
	//draw_right_4(ctx);
	//draw_right_5(ctx);
	//draw_right_6(ctx);
	draw_right_7(ctx);
	//draw_right_8(ctx);
	//draw_right_9(ctx);
	draw_rhombus(ctx);
}

void draw_seven(GContext *ctx) {
	draw_left_diag_1(ctx);
	//draw_left_diag_2(ctx);
	//draw_left_diag_3(ctx);
	//draw_left_diag_4(ctx);
	//draw_left_1(ctx);
	//draw_left_2(ctx);
	//draw_left_3(ctx);
	//draw_left_4(ctx);
	//draw_left_5(ctx);
	//draw_left_6(ctx);
	//draw_left_7(ctx);
	//draw_left_8(ctx);
	//draw_left_9(ctx);
	draw_right_diag_1(ctx);
	//draw_right_diag_2(ctx);
	//draw_right_diag_3(ctx);
	//draw_right_diag_4(ctx);
	//draw_right_1(ctx);
	//draw_right_2(ctx);
	draw_right_3(ctx);
	draw_right_4(ctx);
	draw_right_5(ctx);
	draw_right_6(ctx);
	draw_right_7(ctx);
	draw_right_8(ctx);
	draw_right_9(ctx);
}

void draw_eight(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_left_diag_2(ctx);
	draw_left_diag_3(ctx);
	draw_left_diag_4(ctx);
	//draw_left_1(ctx);
	//draw_left_2(ctx);
	draw_left_3(ctx);
	//draw_left_4(ctx);
	//draw_left_5(ctx);
	//draw_left_6(ctx);
	draw_left_7(ctx);
	//draw_left_8(ctx);
	//draw_left_9(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_2(ctx);
	draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	//draw_right_1(ctx);
	//draw_right_2(ctx);
	draw_right_3(ctx);
	//draw_right_4(ctx);
	//draw_right_5(ctx);
	//draw_right_6(ctx);
	draw_right_7(ctx);
	//draw_right_8(ctx);
	//draw_right_9(ctx);
	draw_rhombus(ctx);
}

void draw_nine(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_left_diag_2(ctx);
	//draw_left_diag_3(ctx);
	draw_left_diag_4(ctx);
	//draw_left_1(ctx);
	//draw_left_2(ctx);
	draw_left_3(ctx);
	//draw_left_4(ctx);
	//draw_left_5(ctx);
	//draw_left_6(ctx);
	//draw_left_7(ctx);
	//draw_left_8(ctx);
	//draw_left_9(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_2(ctx);
	//draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	//draw_right_1(ctx);
	//draw_right_2(ctx);
	draw_right_3(ctx);
	draw_right_4(ctx);
	draw_right_5(ctx);
	draw_right_6(ctx);
	draw_right_7(ctx);
	//draw_right_8(ctx);
	//draw_right_9(ctx);
	draw_rhombus(ctx);
}


/* *** Public function to call relevant draw function *** */

void drawdigit(GContext *ctx, int val) {
	switch(val) {
		case 0:
			draw_zero(ctx);
			break;
		case 1:
			draw_one(ctx);
			break;
		case 2:
			draw_two(ctx);
			break;
		case 3:
			draw_three(ctx);
			break;
		case 4:
			draw_four(ctx);
			break;
		case 5:
			draw_five(ctx);
			break;
		case 6:
			draw_six(ctx);
			break;
		case 7:
			draw_seven(ctx);
			break;
		case 8:
			draw_eight(ctx);
			break;
		case 9:
			draw_nine(ctx);
			break;
		default:
			draw_eight(ctx);
			break;
	}
}