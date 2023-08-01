#ifndef __GTLD_ELEMENT
#define __GTLD_ELEMENT

#include <SDL_pixels.h>

#include <getlaid-container.h>
#include <getlaid-padding.h>

typedef struct GTLD_Element {
	int id;

	GTLD_Rect bounds;
	GTLD_Padding padding;
	GTLD_Container container;
	struct GTLD_Element* children;
	int capacity;
	int count;
} GTLD_Element;

GTLD_Rect* GTLD_GetChildrenBounds(
	GTLD_Container* c,
	GTLD_Rect parent_rect,
	int child_count
);

#endif
