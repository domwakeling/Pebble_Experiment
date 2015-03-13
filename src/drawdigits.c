#include <pebble.h>
#include "drawdigits.h"

/* *** PATH STRUCTS *** */	

const GPathInfo EIGHT_UPPER_LEFT_DIAGONAL = {
	.num_points = 6,
	.points = (GPoint[]) {{13,0}, {14,0}, {14,2}, {2,14}, {0,14}, {0,13}}
};

const GPathInfo EIGHT_UPPER_RIGHT_DIAGONAL = {
	.num_points = 6,
	.points = (GPoint[]) {{16,0}, {17,0}, {30,13}, {30,14}, {28,14}, {16,2}}
};

const GPathInfo EIGHT_UPPER_LEFT_VERTICAL = {
	.num_points = 4,
	.points = (GPoint[]) {{0,16}, {2,16}, {2,22}, {0,22}}
};

const GPathInfo EIGHT_UPPER_RIGHT_VERTICAL = {
	.num_points = 4,
	.points = (GPoint[]) {{28,16}, {30,16}, {30,22}, {28,22}}
};

const GPathInfo EIGHT_SECOND_LEFT_DIAGONAL = {
	.num_points = 6,
	.points = (GPoint[]) {{0,24}, {2,24}, {14,36}, {14,38}, {13,38}, {0,25}}
};

const GPathInfo EIGHT_SECOND_RIGHT_DIAGONAL = {
	.num_points = 6,
	.points = (GPoint[]) {{30,24}, {30,25}, {17,38}, {16,38}, {16,36}, {28,24}}
};

const GPathInfo EIGHT_THIRD_LEFT_DIAGONAL = {
	.num_points = 6,
	.points = (GPoint[]) {{13,40}, {14,40}, {14,42}, {2,54}, {0,54}, {0,53}}
};

const GPathInfo EIGHT_THIRD_RIGHT_DIAGONAL = {
	.num_points = 6,
	.points = (GPoint[]) {{16,40}, {17,40}, {30,53}, {30,54}, {28,54}, {16,42}}
};

const GPathInfo EIGHT_LOWER_LEFT_VERTICAL = {
	.num_points = 4,
	.points = (GPoint[]) {{0,56}, {2,56}, {2,62}, {0,62}}
};

const GPathInfo EIGHT_LOWER_RIGHT_VERTICAL = {
	.num_points = 4,
	.points = (GPoint[]) {{28,56}, {30,56}, {30,62}, {28,62}}
};

const GPathInfo EIGHT_FOURTH_LEFT_DIAGONAL = {
	.num_points = 6,
	.points = (GPoint[]) {{0,64}, {2,64}, {14,76}, {14,78}, {13,78}, {0,65}}
};

const GPathInfo EIGHT_FOURTH_RIGHT_DIAGONAL = {
	.num_points = 6,
	.points = (GPoint[]) {{30,64}, {30,65}, {17,78}, {16,78}, {16,76}, {28,64}}
};

const GPathInfo NINE_UPPER_LEG = {
	.num_points = 4,
	.points = (GPoint[]) {{30,28}, {30,44}, {28,44}, {28,31}}
};

const GPathInfo NINE_LOWER_LEG = {
	.num_points = 4,
	.points = (GPoint[]) {{28,46}, {30,46}, {30,62}, {28,62}}
};

const GPathInfo SIX_UPPER_LEG = {
	.num_points = 4,
	.points = (GPoint[]) {{0,16}, {2,16}, {2,32}, {0,32}}
};

const GPathInfo SIX_LOWER_LEG = {
	.num_points = 4,
	.points = (GPoint[]) {{0,34}, {2,34}, {2,52}, {0,55}}
};

const GPathInfo ZERO_UPPER_LEFT = {
	.num_points = 4,
	.points = (GPoint[]) {{0,16}, {2,16}, {2,30}, {0,30}}
};

const GPathInfo ZERO_UPPER_RIGHT = {
	.num_points = 4,
	.points = (GPoint[]) {{28,16}, {30,16}, {30,30}, {28,30}}
};

const GPathInfo ZERO_MIDDLE_LEFT = {
	.num_points = 4,
	.points = (GPoint[]) {{0,32}, {2,32}, {2,46}, {0,46}}
};

const GPathInfo ZERO_MIDDLE_RIGHT = {
	.num_points = 4,
	.points = (GPoint[]) {{28,32}, {30,32}, {30,46}, {28,46}}
};

const GPathInfo ZERO_LOWER_LEFT = {
	.num_points = 4,
	.points = (GPoint[]) {{0,48}, {2,48}, {2,62}, {0,62}}
};

const GPathInfo ZERO_LOWER_RIGHT = {
	.num_points = 4,
	.points = (GPoint[]) {{28,48}, {30,48}, {30,62}, {28,62}}
};

const GPathInfo SEVEN_BAR_LEFT = {
	.num_points = 4,
	.points = (GPoint[]) {{0,0}, {14,0}, {14,1}, {0,1}}
};

const GPathInfo SEVEN_BAR_RIGHT = {
	.num_points = 4,
	.points = (GPoint[]) {{16,0}, {30,0}, {30,1}, {16,1}}
};

const GPathInfo SEVEN_TOP_RIGHT = {
	.num_points = 4,
	.points = (GPoint[]) {{30,3}, {30,17}, {28,17}, {28,3}}
	//.points = (GPoint[]) {{30,14}, {30,17}, {28,17}, {28,14}}
};

const GPathInfo SEVEN_SECOND_RIGHT_DIAGONAL = {
	.num_points = 6,
	.points = (GPoint[]) {{30,19}, {30,20}, {18,32}, {16,32}, {16,31}, {28,19}}
};

const GPathInfo SEVEN_UPPER_MIDDLE = {
	.num_points = 4,
	.points = (GPoint[]) {{18,34}, {18,47}, {16,47}, {16,34}}
};

const GPathInfo SEVEN_MIDDLE_MIDDLE = {
	.num_points = 4,
	.points = (GPoint[]) {{18,49}, {18,62}, {16,62}, {16,49}}
};

const GPathInfo SEVEN_LOWER_MIDDLE = {
	.num_points = 4,
	.points = (GPoint[]) {{18,64}, {18,78}, {16,78}, {16,64}}
};

const GPathInfo ONE_FIRST = {
	.num_points = 4,
	.points = (GPoint[]) {{14,0}, {16,0}, {16,14}, {14,14}}
};

const GPathInfo ONE_SECOND = {
	.num_points = 4,
	.points = (GPoint[]) {{14,16}, {16,16}, {16,30}, {14,30}}
};

const GPathInfo ONE_THIRD = {
	.num_points = 4,
	.points = (GPoint[]) {{14,32}, {16,32}, {16,46}, {14,46}}
};

const GPathInfo ONE_FOURTH = {
	.num_points = 4,
	.points = (GPoint[]) {{14,48}, {16,48}, {16,62}, {14,62}}
};

const GPathInfo ONE_FIFTH = {
	.num_points = 4,
	.points = (GPoint[]) {{14,64}, {16,64}, {16,78}, {14,78}}
};

const GPathInfo FOUR_SECOND_LEFT_DIAGONAL = {
	.num_points = 5,
	.points = (GPoint[]) {{0,24}, {2,24}, {12,34}, {12,38}, {0,25}}
};

const GPathInfo FOUR_UPPER_LEFT_VERTICAL = {
	.num_points = 4,
	.points = (GPoint[]) {{0,16}, {2,16}, {2,35}, {0,35}}
};

const GPathInfo FOUR_LEFT_BAR = {
	.num_points = 4,
	.points = (GPoint[]) {{0,37}, {12,37}, {12,38}, {0,37}}
};

const GPathInfo FOUR_RIGHT_BAR = {
	.num_points = 4,
	.points = (GPoint[]) {{18,37}, {30,37}, {30,38}, {18,38}}
};

/* *** Functions to draw paths *** */

void draw_eight_upper_left_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_UPPER_LEFT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_upper_right_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_UPPER_RIGHT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}
void draw_eight_upper_left_vertical(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_UPPER_LEFT_VERTICAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_upper_right_vertical(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_UPPER_RIGHT_VERTICAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_second_left_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_SECOND_LEFT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_second_right_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_SECOND_RIGHT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_third_left_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_THIRD_LEFT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_third_right_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_THIRD_RIGHT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_lower_left_vertical(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_LOWER_LEFT_VERTICAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_lower_right_vertical(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_LOWER_RIGHT_VERTICAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_fourth_left_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_FOURTH_LEFT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_eight_fourth_right_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&EIGHT_FOURTH_RIGHT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_nine_upper_leg(GContext *ctx) {
	GPath *t_path = gpath_create(&NINE_UPPER_LEG);
	gpath_draw_filled(ctx, t_path);
}

void draw_nine_lower_leg(GContext *ctx) {
	GPath *t_path = gpath_create(&NINE_LOWER_LEG);
	gpath_draw_filled(ctx, t_path);
}

void draw_six_upper_leg(GContext *ctx) {
	GPath *t_path = gpath_create(&SIX_UPPER_LEG);
	gpath_draw_filled(ctx, t_path);
}

void draw_six_lower_leg(GContext *ctx) {
	GPath *t_path = gpath_create(&SIX_LOWER_LEG);
	gpath_draw_filled(ctx, t_path);
}

void draw_zero_upper_left(GContext *ctx) {
	GPath *t_path = gpath_create(&ZERO_UPPER_LEFT);
	gpath_draw_filled(ctx, t_path);
}

void draw_zero_upper_right(GContext *ctx) {
	GPath *t_path = gpath_create(&ZERO_UPPER_RIGHT);
	gpath_draw_filled(ctx, t_path);
}

void draw_zero_midde_left(GContext *ctx) {
	GPath *t_path = gpath_create(&ZERO_MIDDLE_LEFT);
	gpath_draw_filled(ctx, t_path);
}

void draw_zero_middle_right(GContext *ctx) {
	GPath *t_path = gpath_create(&ZERO_MIDDLE_RIGHT);
	gpath_draw_filled(ctx, t_path);
}

void draw_zero_lower_left(GContext *ctx) {
	GPath *t_path = gpath_create(&ZERO_LOWER_LEFT);
	gpath_draw_filled(ctx, t_path);
}

void draw_zero_lower_right(GContext *ctx) {
	GPath *t_path = gpath_create(&ZERO_LOWER_RIGHT);
	gpath_draw_filled(ctx, t_path);
}

void draw_seven_bar_left(GContext *ctx) {
	GPath *t_path = gpath_create(&SEVEN_BAR_LEFT);
	gpath_draw_filled(ctx, t_path);
}

void draw_seven_bar_right(GContext *ctx) {
	GPath *t_path = gpath_create(&SEVEN_BAR_RIGHT);
	gpath_draw_filled(ctx, t_path);
}
void draw_seven_top_right(GContext *ctx) {
	GPath *t_path = gpath_create(&SEVEN_TOP_RIGHT);
	gpath_draw_filled(ctx, t_path);
}

void draw_seven_second_right_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&SEVEN_SECOND_RIGHT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_seven_upper_middle(GContext *ctx) {
	GPath *t_path = gpath_create(&SEVEN_UPPER_MIDDLE);
	gpath_draw_filled(ctx, t_path);
}

void draw_seven_middle_middle(GContext *ctx) {
	GPath *t_path = gpath_create(&SEVEN_MIDDLE_MIDDLE);
	gpath_draw_filled(ctx, t_path);
}

void draw_seven_lower_middle(GContext *ctx) {
	GPath *t_path = gpath_create(&SEVEN_LOWER_MIDDLE);
	gpath_draw_filled(ctx, t_path);
}

void draw_one_first(GContext *ctx) {
	GPath *t_path = gpath_create(&ONE_FIRST);
	gpath_draw_filled(ctx, t_path);
}

void draw_one_second(GContext *ctx) {
	GPath *t_path = gpath_create(&ONE_SECOND);
	gpath_draw_filled(ctx, t_path);
}

void draw_one_third(GContext *ctx) {
	GPath *t_path = gpath_create(&ONE_THIRD);
	gpath_draw_filled(ctx, t_path);
}

void draw_one_fourth(GContext *ctx) {
	GPath *t_path = gpath_create(&ONE_FOURTH);
	gpath_draw_filled(ctx, t_path);
}

void draw_one_fifth(GContext *ctx) {
	GPath *t_path = gpath_create(&ONE_FIFTH);
	gpath_draw_filled(ctx, t_path);
}

void draw_four_upper_left_vertical(GContext *ctx) {
	GPath *t_path = gpath_create(&FOUR_UPPER_LEFT_VERTICAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_four_second_left_diagonal(GContext *ctx) {
	GPath *t_path = gpath_create(&FOUR_SECOND_LEFT_DIAGONAL);
	gpath_draw_filled(ctx, t_path);
}

void draw_four_left_bar(GContext *ctx) {
	GPath *t_path = gpath_create(&FOUR_LEFT_BAR);
	gpath_draw_filled(ctx, t_path);
}

void draw_four_right_bar(GContext *ctx) {
	GPath *t_path = gpath_create(&FOUR_RIGHT_BAR);
	gpath_draw_filled(ctx, t_path);
}

/* *** Functions to draw numbers from paths *** */

void draw_zero(GContext *ctx) {
	draw_eight_upper_left_diagonal(ctx);
	draw_eight_upper_right_diagonal(ctx);
	draw_eight_fourth_left_diagonal(ctx);
	draw_eight_fourth_right_diagonal(ctx);
	draw_zero_upper_left(ctx);
	draw_zero_midde_left(ctx);
	draw_zero_lower_left(ctx);
	draw_zero_upper_right(ctx);
	draw_zero_middle_right(ctx);
	draw_zero_lower_right(ctx);
}

void draw_one(GContext *ctx) {
	draw_one_first(ctx);
	draw_one_second(ctx);
	draw_one_third(ctx);
	draw_one_fourth(ctx);
	draw_one_fifth(ctx);
}
															 
void draw_two(GContext *ctx) {
	draw_eight_upper_left_diagonal(ctx);
	draw_eight_upper_right_diagonal(ctx);
	draw_eight_upper_left_vertical(ctx);
	draw_eight_upper_right_vertical(ctx);
	draw_eight_second_right_diagonal(ctx);
	draw_eight_third_left_diagonal(ctx);
	draw_eight_lower_left_vertical(ctx);
	draw_eight_lower_right_vertical(ctx);
	draw_eight_fourth_left_diagonal(ctx);
	draw_eight_fourth_right_diagonal(ctx);
}

void draw_three(GContext *ctx) {
	draw_eight_upper_left_diagonal(ctx);
	draw_eight_upper_right_diagonal(ctx);
	draw_eight_upper_left_vertical(ctx);
	draw_eight_upper_right_vertical(ctx);
	draw_eight_second_right_diagonal(ctx);
	draw_eight_third_right_diagonal(ctx);
	draw_eight_lower_left_vertical(ctx);
	draw_eight_lower_right_vertical(ctx);
	draw_eight_fourth_left_diagonal(ctx);
	draw_eight_fourth_right_diagonal(ctx);
}

void draw_four(GContext *ctx) {
	draw_eight_upper_left_diagonal(ctx);
	//draw_eight_upper_left_vertical(ctx);
	//draw_four_second_left_diagonal(ctx);
	draw_four_upper_left_vertical(ctx);
	draw_four_left_bar(ctx);
	draw_four_right_bar(ctx);
	draw_one_third(ctx);
	draw_one_fourth(ctx);
	draw_one_fifth(ctx);
}

void draw_five(GContext *ctx) {
	draw_eight_upper_left_diagonal(ctx);
	draw_eight_upper_right_diagonal(ctx);
	draw_eight_upper_left_vertical(ctx);
	draw_eight_upper_right_vertical(ctx);
	draw_eight_second_left_diagonal(ctx);
	draw_eight_third_right_diagonal(ctx);
	draw_eight_lower_left_vertical(ctx);
	draw_eight_lower_right_vertical(ctx);
	draw_eight_fourth_left_diagonal(ctx);
	draw_eight_fourth_right_diagonal(ctx);
}

void draw_six(GContext *ctx) {
	draw_eight_upper_left_diagonal(ctx);
	draw_eight_upper_right_diagonal(ctx);
	draw_eight_third_left_diagonal(ctx);
	draw_eight_third_right_diagonal(ctx);
	draw_eight_lower_left_vertical(ctx);
	draw_eight_lower_right_vertical(ctx);
	draw_eight_fourth_left_diagonal(ctx);
	draw_eight_fourth_right_diagonal(ctx);
	draw_six_upper_leg(ctx);
	draw_six_lower_leg(ctx);
}

void draw_seven(GContext *ctx) {
	//draw_eight_upper_left_diagonal(ctx);
	//draw_eight_upper_right_diagonal(ctx);
	//draw_eight_upper_left_vertical(ctx);
	draw_seven_bar_left(ctx);
	draw_seven_bar_right(ctx);
	draw_seven_second_right_diagonal(ctx);
	draw_seven_upper_middle(ctx);
	draw_seven_middle_middle(ctx);
	draw_seven_lower_middle(ctx);
	draw_seven_top_right(ctx);
}

void draw_eight(GContext *ctx) {
	draw_eight_upper_left_diagonal(ctx);
	draw_eight_upper_right_diagonal(ctx);
	draw_eight_upper_left_vertical(ctx);
	draw_eight_upper_right_vertical(ctx);
	draw_eight_second_left_diagonal(ctx);
	draw_eight_second_right_diagonal(ctx);
	draw_eight_third_left_diagonal(ctx);
	draw_eight_third_right_diagonal(ctx);
	draw_eight_lower_left_vertical(ctx);
	draw_eight_lower_right_vertical(ctx);
	draw_eight_fourth_left_diagonal(ctx);
	draw_eight_fourth_right_diagonal(ctx);
}

void draw_nine(GContext *ctx) {
	draw_eight_upper_left_diagonal(ctx);
	draw_eight_upper_right_diagonal(ctx);
	draw_eight_upper_left_vertical(ctx);
	draw_eight_upper_right_vertical(ctx);
	draw_eight_second_left_diagonal(ctx);
	draw_eight_second_right_diagonal(ctx);
	draw_eight_fourth_left_diagonal(ctx);
	draw_eight_fourth_right_diagonal(ctx);
	draw_nine_upper_leg(ctx);
	draw_nine_lower_leg(ctx);
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