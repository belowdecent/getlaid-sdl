#ifndef __GTLD_AXIS
#define __GTLD_AXIS

#include <getlaid-units.h>

typedef enum GTLD_Alignment {
	GTLD_ALIGN_BEGIN,
	GTLD_ALIGN_CENTER,
	GTLD_ALIGN_END
} GTLD_Alignment;

typedef struct GTLD_Axis {
	GTLD_Alignment alignment;
	GTLD_Unit* layout;
	int count;
} GTLD_Axis;

int GTLD_SetAxis(
	GTLD_Axis* axis,
	int layout_count,
	GTLD_Unit* layout
);

#endif 

