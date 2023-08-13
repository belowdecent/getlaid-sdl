#include <getlaid-axis.h>
#include <stdlib.h>

#include "getlaid-units.h"

int GTLD_SetAxis(
  GTLD_Axis* axis, int count, const GTLD_Unit* layout
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

GTLD_Axis* GTLD_AutoAxis() {
  GTLD_Axis* axis = malloc(sizeof(GTLD_Axis));
  GTLD_Unit* layout = malloc(sizeof(GTLD_Unit));
  layout->unit = GTLD_UNIT_AUTO;

  *axis = (GTLD_Axis){
    .layout = layout,
    .count = 1,
    .alignment = GTLD_ALIGN_BEGIN};

  return axis;
}
