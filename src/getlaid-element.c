#include <getlaid-element.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ResizingState {
	GTLD_Rect parent_rect;
	GTLD_Rect* rects;
	int count;

	int free_space_main;
} ResizingState;


int GTLD_UnitToPX(
	GTLD_Unit unit, 
	int container_size, 
	int auto_width
) {
	switch (unit.unit) {
		case GTLD_UNIT_AUTO:
			return auto_width;
		case GTLD_UNIT_PX:
			return unit.value;
		case GTLD_UNIT_PERCENT:
			return unit.value * container_size;
		default:
			fprintf(stderr, "BAD UNIT!!\n");
			exit(1);
	}
}

#define MIN(a, b) ((a) < (b)) ? (a) : (b)
#define COORD(bound, dir) (*(dir == GTLD_ROW ? &(bound)->x : &(bound)->y))
#define SIZE(bound, dir)  (*(dir == GTLD_ROW ? &(bound)->w : &(bound)->h))

static int set_main_axis_sizes(
	ResizingState* state,
	GTLD_Axis main, 
	GTLD_Direction dir
) {
	GTLD_Rect** auto_target_ptrs = malloc(sizeof(GTLD_Rect*) * state->count);
	int auto_count = 0;

	for (int i = 0; i < state->count; ++i) {
		GTLD_Unit unit = main.layout[MIN(main.count - 1, i)];
		if (unit.unit == GTLD_UNIT_AUTO) {
			auto_target_ptrs[auto_count] = &state->rects[i];
			++auto_count;
			continue;
		}

		SIZE(&state->rects[i], dir) = GTLD_UnitToPX(
			main.layout[MIN(main.count - 1, i)], 
			SIZE(&state->parent_rect, dir),
			0
		);
		state->free_space_main -= SIZE(&state->rects[i], dir);
	}

	for (int i = 0; i < auto_count; ++i) {
		SIZE(auto_target_ptrs[i], dir) = state->free_space_main / auto_count;
	}

	if (auto_count) 
		state->free_space_main = 0;

	return 0;
}

static int set_main_axis_coords(
	ResizingState* state, 
	GTLD_Alignment main_align, 
	GTLD_Direction dir
) {
	COORD(&state->rects[0], dir) = COORD(&state->parent_rect, dir);

	switch (main_align) {
		case GTLD_ALIGN_BEGIN: break;
		case GTLD_ALIGN_CENTER:
			COORD(&state->rects[0], dir) += state->free_space_main / 2;
			break;
		case GTLD_ALIGN_END:
			COORD(&state->rects[0], dir) += state->free_space_main;
			break;
	}

	for (int i = 1; i < state->count; ++i) {
		COORD(&state->rects[i], dir) = COORD(&state->rects[i-1], dir);
		COORD(&state->rects[i], dir) += SIZE(&state->rects[i-1], dir);
	}

	return 0;
}

static int set_cross_axis_sizes(
	ResizingState* state, 
	GTLD_Axis cross, 
	GTLD_Direction dir
) {
	for (int i = 0; i < state->count; ++i) {
		SIZE(&state->rects[i], dir) = GTLD_UnitToPX(
			cross.layout[MIN(cross.count - 1, i)], 
			SIZE(&state->parent_rect, dir), 
			SIZE(&state->parent_rect, dir) 
		);
	}

	return 0;
}

static int set_cross_axis_coords(
	ResizingState* state,
	GTLD_Alignment align,
	GTLD_Direction dir
) {
	for (int i = 0; i < state->count; ++i) {
		COORD(&state->rects[i], dir) = COORD(&state->parent_rect, dir);

		switch (align) {
			case GTLD_ALIGN_BEGIN: break;
			case GTLD_ALIGN_CENTER:
				COORD(&state->rects[i], dir) += SIZE(&state->parent_rect, dir);
				COORD(&state->rects[i], dir) -= SIZE(&state->rects[i], dir) / 2;
				break;
			case GTLD_ALIGN_END:
				COORD(&state->rects[i], dir) += SIZE(&state->parent_rect, dir);
				COORD(&state->rects[i], dir) -= SIZE(&state->rects[i], dir);
				break;
		}
	}

	return 0;
}

GTLD_Rect* GTLD_GetChildrenBounds(
	GTLD_Container* c,
	GTLD_Rect parent_rect,
	int child_count
) {
	ResizingState state = {
		.rects = malloc(sizeof(GTLD_Rect) * child_count), 
		.parent_rect = parent_rect, 
		.count = child_count, 
		.free_space_main = SIZE(&parent_rect, c->direction)
	};

	const GTLD_Direction main_dir = c->direction;
	const GTLD_Direction cross_dir = 
		(main_dir == GTLD_ROW)
		? GTLD_COLUMN
		: GTLD_ROW;

	set_main_axis_sizes(&state, c->main, main_dir);
	set_main_axis_coords(&state, c->main.alignment, main_dir);
	set_cross_axis_sizes(&state, c->cross, cross_dir);
	set_cross_axis_coords(&state, c->cross.alignment, cross_dir);

	return state.rects;
}
