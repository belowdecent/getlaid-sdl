#include <getlaid-axis.h>
#include <stdlib.h>

int GTLD_SetAxis(
	GTLD_Axis *axis, 
	int count, 
	GTLD_Unit *layout
) {
	if (axis == NULL) 
		return 1;

	axis->layout = malloc(sizeof(GTLD_Unit) * count);
	axis->count = count;

	for (int i = 0; i < count; ++count) {
		axis->layout[i] = layout[i];
	}

	return 0;
}
