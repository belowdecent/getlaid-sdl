#include <SDL_rect.h>
#include <SDL_pixels.h>
#include <getlaid-units.h>

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
	SDL_Rect bounds;
	SDL_Color color;

	GTLD_Padding padding;

	struct GTLD_Element* children;
	int count;
} GTLD_Element;
