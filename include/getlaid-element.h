#ifndef __GTLD_ELEMENT
#define __GTLD_ELEMENT

#include <SDL_rect.h>
#include <SDL_pixels.h>

#include <getlaid-container.h>

typedef SDL_Rect GTLD_Rect;

typedef struct GTLD_Padding {
	GTLD_Unit top;
	GTLD_Unit right;
	GTLD_Unit bottom;
	GTLD_Unit left;
} GTLD_Padding;

#define GTLD_PADDING_ALL(unit, value) \
(GTLD_Padding) {\
	{unit, value},\
	{unit, value},\
	{unit, value},\
	{unit, value}\
}

#define GTLD_PADDING_INLINE(unit, value) \
(GTLD_Padding) {\
	{0},\
	{unit, value},\
	{0},\
	{unit, value}\
}

#define GTLD_PADDING_BLOCK(unit, value) \
(GTLD_Padding) {\
	{unit, value},\
	{0},\
	{unit, value},\
	{0}\
}

typedef struct GTLD_Element {
	GTLD_Rect bounds;
	SDL_Color color;

	GTLD_Padding padding;

	struct GTLD_Element* children;
	int count;
} GTLD_Element;

int GTLD_UnitToPX(
	GTLD_Unit unit, 
	int container_size, 
	int auto_width
);

GTLD_Rect* GTLD_GetChildrenBounds(
	GTLD_Container* c,
	GTLD_Rect parent_rect,
	int child_count
);

#endif
