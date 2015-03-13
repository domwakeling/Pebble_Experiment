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
		.points = (GPoint[]) {{0,0}, {3,0}, {3,14}, {0,11}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_2(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,11}, {3,8}, {3,14}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_3(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,16}, {3,19}, {3,24}, {0,27}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,32}, {3,29}, {3,35}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_5(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,37}, {3,40}, {3,51}, {0,54}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_6(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,59}, {3,56}, {3,62}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_7(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,64}, {3,67}, {3,72}, {0,75}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_8(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{0,80}, {3,77}, {3,83}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_left_9(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{0,80}, {3,77}, {3,91}, {0,91}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_1(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,0}, {27,0}, {27,14}, {30,11}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_2(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,11}, {27,8}, {27,14}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_3(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,16}, {27,19}, {27,24}, {30,27}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,32}, {27,29}, {27,35}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_5(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,37}, {27,40}, {27,51}, {30,54}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_6(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,59}, {27,56}, {27,62}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_7(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,64}, {27,67}, {27,72}, {30,75}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_8(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 3,
		.points = (GPoint[]) {{30,80}, {27,77}, {27,83}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);
}

void draw_right_9(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 4,
		.points = (GPoint[]) {{30,80}, {27,77}, {27,91}, {30,91}}
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
		.num_points = 5,
		.points = (GPoint[]) {{0,32}, {3,29}, {13,39}, {13,43}, {11,43}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_left_diag_3(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{0,59}, {11,48}, {13,48}, {13,52}, {3,62}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_left_diag_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{0,80}, {3,77}, {13,87}, {13,91}, {11,91}}
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
		.num_points = 5,
		.points = (GPoint[]) {{30,32}, {27,29}, {17,39}, {17,43}, {19,43}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_right_diag_3(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{30,59}, {19,48}, {17,48}, {17,52}, {27,62}}
	};
	custom_draw_gpathinfo(ctx, &TEMP);	
}

void draw_right_diag_4(GContext *ctx) {
	GPathInfo TEMP = {
		.num_points = 5,
		.points = (GPoint[]) {{30,80}, {27,77}, {17,87}, {17,91}, {19,91}}
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
}

void draw_four(GContext *ctx) {
	//draw_left_diag_1(ctx);
	draw_left_diag_2(ctx);
	//draw_left_diag_3(ctx);
	//draw_left_diag_4(ctx);
	draw_left_1(ctx);
	//draw_left_2(ctx);
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
	//draw_right_2(ctx);
	draw_right_3(ctx);
	draw_right_4(ctx);
	draw_right_5(ctx);
	draw_right_6(ctx);
	draw_right_7(ctx);
	//draw_right_8(ctx);
	draw_right_9(ctx);
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