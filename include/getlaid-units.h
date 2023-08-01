#ifndef __GTLD_UNITS
#define __GTLD_UNITS

typedef enum GTLD_UnitType {
	GTLD_UNIT_PX,
	GTLD_UNIT_PERCENT,
	GTLD_UNIT_AUTO
} GTLD_UnitType;

typedef struct GTLD_Unit {
	GTLD_UnitType unit;
	double value;
} GTLD_Unit;

int GTLD_UnitToPX(
	GTLD_Unit unit, 
	int container_size, 
	int auto_width
);

static const GTLD_Unit GTLD_AUTOSIZE = (GTLD_Unit) {GTLD_UNIT_AUTO, 0}; 

#endif
