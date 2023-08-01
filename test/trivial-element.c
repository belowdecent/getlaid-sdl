#include "getlaid-axis.h"
#include "getlaid-container.h"
#include "getlaid-element.h"
#include <assert.h>
#include <getlaid-sdl.h>
#include <stdio.h>
#include <stdlib.h>

#define PARENT_X 20
#define PARENT_Y 10
#define PARENT_W 100
#define PARENT_H 100

#define assert_with_msg(expr) assert((expr) && debug_message)
int main() {
	GTLD_Element el = {
		.count = 2,
		.children = malloc(sizeof(GTLD_Element) * 2), 
		.bounds = {
			.x = PARENT_X, 
			.y = PARENT_Y, 
			.w = PARENT_W, 
			.h = PARENT_H
		},
		.container = GTLD_AUTOCONTAINER(GTLD_ROW, GTLD_ALIGN_BEGIN, GTLD_ALIGN_CENTER)
	};

	el.children[0] = (GTLD_Element) {0};
	el.children[1] = (GTLD_Element) {0};

	GTLD_Rect* rect = GTLD_GetChildrenBounds(&el.container, el.bounds, 2);

	for (int i = 0; i < el.count; ++i) {
		el.children[i].bounds = rect[i];
	}

	free(rect);

	for (int i = 0; i < el.count; ++i) {
		printf(
			"Child %i width: %i. Expected: %i\n", 
			i, el.children[i].bounds.w, PARENT_W / 2
		);
		assert(el.children[i].bounds.w == PARENT_W / 2);

		printf(
			"Child %i height: %i. Expected: %i\n", 
			i, el.children[i].bounds.h, PARENT_H
		);
		assert(el.children[i].bounds.h == PARENT_H);

		printf(
			"Child %i y: %i. Expected: %i\n", 
			i, el.children[i].bounds.y, PARENT_Y
		);
		assert(el.children[i].bounds.y == PARENT_Y);
	}
	
	printf(
		"Child 0 x: %i. Expected: %i\n", 
		el.children[0].bounds.x, PARENT_X
	);
	assert(el.children[0].bounds.x == PARENT_X);
	printf(
		"Child 0 x: %i. Expected: %i\n", 
		el.children[1].bounds.x, PARENT_X + PARENT_W / 2
	);
	assert(el.children[1].bounds.x == PARENT_X + PARENT_W / 2);

	return 0;
}
