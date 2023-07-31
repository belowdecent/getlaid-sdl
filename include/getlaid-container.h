#ifndef __GTLD_CONTAINER
#define __GTLD_CONTAINER

#include <getlaid-axis.h>

typedef enum GTLD_Direction {
	GTLD_ROW,
	GTLD_COLUMN,
} GTLD_Direction;

typedef enum GTLD_Repeat {
	GTLD_REPEAT_LAST,
	GTLD_REPEAT_CYCLE,
	GTLD_REPEAT_WRAP,
	GTLD_REPEAT_NONE,
} GTLD_Repeat;

typedef struct GTLD_Container {
	GTLD_Direction direction;
	GTLD_Repeat repeat;

	GTLD_Axis main;
	GTLD_Axis cross;
} GTLD_Container;

#define GTLD_AUTOCONTAINER(direction, main_align, cross_align)\
(GTLD_Container) {\
	.direction = direction,\
	.main = {\
		.layout = &GTLD_AUTOSIZE,\
		.count = 1,\
		.alignment = main_align,\
	},\
	.cross = {\
		.layout = &GTLD_AUTOSIZE,\
		.count = 1,\
		.alignment = cross_align,\
	}\
}

#endif 



