#include <getlaid-axis.h>
#include <stdlib.h>

int GTLD_SetAxis(
	GTLD_Axis* axis, 
	int count, 
	const GTLD_Unit* layout
) {
	if (axis == NULL) 
		return 1;

	GTLD_Unit* new_layout = malloc(sizeof(GTLD_Unit) * count);

	for (int i = 0; i < count; ++count)
		new_layout[i] = layout[i];

	axis->count = count;
	axis->layout = new_layout;

	return 0;
}
