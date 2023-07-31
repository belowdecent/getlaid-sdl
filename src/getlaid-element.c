#include "getlaid-axis.h"
#include "getlaid-units.h"
#include <getlaid-element.h>
#include <stdio.h>


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

#define MIN(a, b) (a < b) ? a : b
#define CROSS_COORD(bound, dir) (*((dir == GTLD_ROW) ? &(bound)->y : &(bound)->x))
#define CROSS_SIZE(bound, dir)  (*((dir == GTLD_ROW) ? &(bound)->h : &(bound)->w))

GTLD_Rect GTLD_GetChildBounds(
	GTLD_Container* c,
	GTLD_Rect parent_rect,
	int child_count
) {
	GTLD_Rect* bounds = malloc(sizeof(GTLD_Rect) * child_count);
	const GTLD_Axis main = c->main;
	const GTLD_Axis cross = c->cross;

	int is_row = c->direction == GTLD_ROW;

	const int main_coord = is_row ? parent_rect.x : parent_rect.y;
	const int main_size  = is_row ? parent_rect.w : parent_rect.h;

	const GTLD_Unit last_main =	main.layout[main.count - 1];
	const GTLD_Unit last_cross = cross.layout[cross.count - 1];

	int auto_count = 0;
	int* auto_indices = malloc(child_count * sizeof(int));
	{ // count auto-sized elements across main axis
		int count_limit = MIN(child_count, main.count);
		for (int i = 0; i < count_limit; ++i) {
			if (main.layout[i].unit == GTLD_UNIT_AUTO) {
				auto_indices[auto_count] = i;
				++auto_count;
			}
		}

		if (last_main.unit == GTLD_UNIT_AUTO) {
			while (count_limit < child_count) {
				auto_indices[auto_count] = count_limit;
				++auto_count;
				++count_limit;
			}
		}
	}

	int free_space = main_size;
	{ // evaluate free space
		int count_limit = MIN(child_count, main.count);

		for (int i = 0; i < count_limit; ++i) {
			if (main.layout[i].unit != GTLD_UNIT_AUTO) {
				int* resize_target = is_row ? &bounds[i].w : &bounds[i].h;
				*resize_target = GTLD_UnitToPX(main.layout[i], main_size, 0);
				free_space -= *resize_target;
			}
		}

		if (last_main.unit != GTLD_UNIT_AUTO) {
			int size = GTLD_UnitToPX(last_main, main_size, 0);
			for (int i = count_limit; i < child_count; ++i) {
				int* resize_target = is_row ? &bounds[i].w : &bounds[i].h;
				*resize_target = GTLD_UnitToPX(main.layout[i], main_size, 0);
				free_space -= *resize_target;
			}
		}
	}

	int main_auto_size = (auto_count > 0) ? free_space / auto_count : 0;
	int cross_auto_size = is_row ? parent_rect.h : parent_rect.w;

	for (int i = 0; i < auto_count; ++i) {
		int* resize_target = 
			is_row
			? &bounds[auto_indices[i]].w 
			: &bounds[auto_indices[i]].h;
		*resize_target = main_auto_size;
	}
	free(auto_indices);

	int* last_child_coord = is_row ? &bounds[0].x : &bounds[0].y;
	int last_child_size = is_row ? bounds[0].w : bounds[0].h;
	*last_child_coord = main_coord;
	if (auto_count == 0) {
		if (main.alignment == GTLD_ALIGN_CENTER) {
			*last_child_coord += free_space / 2;
		} else if (main.alignment == GTLD_ALIGN_END) {
			*last_child_coord += free_space;
		}
	}


	for (int i = 0; i < child_count - 1; ++i) {
		int* child_coord = is_row ? &bounds[i + 1].x : &bounds[i + 1].y;
		*child_coord = *last_child_coord + last_child_size;
		last_child_coord = child_coord;
		last_child_size = is_row ? bounds[i + 1].w : bounds[i + 1].h;
	}
}
