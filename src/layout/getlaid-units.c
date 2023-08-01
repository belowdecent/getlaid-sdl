#include <getlaid-units.h>

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
	}

	return -1;
}

const GTLD_Unit GTLD_AUTOSIZE = (GTLD_Unit) {GTLD_UNIT_AUTO, 0}; 
