#include <pebble.h>
#include "drawdigits.h"

// Custom drawing function passing in GPathInfo; prevent repeating create/destory in each segment
void custom_draw_gpathinfo(GContext *ctx, GPathInfo *pathinfo) {
	GPath *t_path = gpath_create(pathinfo);
	gpath_draw_filled(ctx, t_path);
	gpath_destroy(t_path);
}

// Individual functions defining GPathInfo and passng to the custom_draw_gpathinfo

void draw_left_1(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,2}, {4,2}, {4,15}, {0,11}}
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
		.points = (GPoint[]) {{0,36}, {4,40}, {4,48}, {0,52}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_6(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,56}, {4,52}, {4,60}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_7(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,60}, {4,64}, {4,68}, {0,72}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_8(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,76}, {4,72}, {4,80}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_9(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,76}, {4,72}, {4,85}, {0,85}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_1(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,2}, {26,2}, {26,15}, {30,11}}
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
		.points = (GPoint[]) {{30,36}, {26,40}, {26,48}, {30,52}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_6(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,56}, {26,52}, {26,60}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_7(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,60}, {26,64}, {26,68}, {30,72}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_8(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,76}, {26,72}, {26,80}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_9(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,76}, {26,72}, {26,85}, {30,85}}
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
		.points = (GPoint[]) {{0,56}, {9,47}, {11,50}, {3,59}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_left_diag_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{0,76}, {3,73}, {13,83}, {13,87}, {11,87}}
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
		.points = (GPoint[]) {{30,56}, {21,47}, {19,50}, {27,59}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_right_diag_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{30,76}, {27,73}, {17,83}, {17,87}, {19,87}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_rhombus(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{12,44}, {15,41}, {18,44}, {15,47}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_rhombus_1_right(GContext *ctx) {
	// 1px to the right, for [3]
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{13,44}, {16,41}, {19,44}, {16,47}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_rhombus_3_low(GContext *ctx) {
	// 3 px lower than standard rhombus, for [6]
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{12,47}, {15,44}, {18,47}, {15,50}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_rhombus_2_high(GContext *ctx) {
	// 2 px higher than standard rhombus, for [4] & [9]
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{12,42}, {15,39}, {18,42}, {15,45}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_center_1(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{13,2}, {17,2}, {17,22}, {13,18}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_center_2(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{13,21}, {17,25}, {17,40}, {13,44}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_center_3(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{13,62}, {17,66}, {17,43}, {13,47}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_center_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{13,85}, {17,85}, {17,69}, {13,65}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}


// *** Functions to draw numbers from paths ***

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
	draw_center_1(ctx);
	draw_center_2(ctx);
	draw_center_3(ctx);
	draw_center_4(ctx);
}
															 
void draw_two(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_left_diag_3(ctx);
	draw_left_diag_4(ctx);
	draw_left_3(ctx);
	draw_left_7(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_2(ctx);
	draw_right_diag_4(ctx);
	draw_right_3(ctx);
	draw_right_7(ctx);
	draw_rhombus(ctx);
}

void draw_three(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_left_diag_4(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_2(ctx);
	draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	draw_right_3(ctx);
	draw_right_7(ctx);
	draw_rhombus_1_right(ctx);
}

void draw_four(GContext *ctx) {
	draw_left_diag_2(ctx);
	draw_left_1(ctx);
	draw_left_2(ctx);
	draw_left_3(ctx);
	draw_right_diag_2(ctx);
	draw_right_1(ctx);
	draw_right_2(ctx);
	draw_right_3(ctx);
	draw_right_4(ctx);
	draw_right_5(ctx);
	draw_right_6(ctx);
	draw_right_7(ctx);
	draw_right_8(ctx);
	draw_right_9(ctx);
	draw_rhombus_2_high(ctx);
}

void draw_five(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_left_diag_2(ctx);
	draw_left_diag_4(ctx);
	draw_left_3(ctx);
	draw_left_7(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	draw_right_3(ctx);
	draw_right_7(ctx);
	draw_rhombus(ctx);
}

void draw_six(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_left_diag_3(ctx);
	draw_left_diag_4(ctx);
	draw_left_3(ctx);
	draw_left_4(ctx);
	draw_left_5(ctx);
	draw_left_6(ctx);
	draw_left_7(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	draw_right_7(ctx);
	draw_rhombus_3_low(ctx);
}

void draw_seven(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_right_diag_1(ctx);
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
	draw_left_3(ctx);
	draw_left_7(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_2(ctx);
	draw_right_diag_3(ctx);
	draw_right_diag_4(ctx);
	draw_right_3(ctx);
	draw_right_7(ctx);
	draw_rhombus(ctx);
}

void draw_nine(GContext *ctx) {
	draw_left_diag_1(ctx);
	draw_left_diag_2(ctx);
	draw_left_diag_4(ctx);
	draw_left_3(ctx);
	draw_right_diag_1(ctx);
	draw_right_diag_2(ctx);
	draw_right_diag_4(ctx);
	draw_right_3(ctx);
	draw_right_4(ctx);
	draw_right_5(ctx);
	draw_right_6(ctx);
	draw_right_7(ctx);
	draw_rhombus_2_high(ctx);
}


// *** Public function to call relevant draw function ***

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