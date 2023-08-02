#include <getlaid-padding.h>

GTLD_Rect GTLD_PadBounds(
  const GTLD_Rect* rect, const GTLD_Padding* padding
) {
  int top = GTLD_UnitToPX(padding->top, rect->h, 0);
  int right = GTLD_UnitToPX(padding->right, rect->w, 0);
  int bottom = GTLD_UnitToPX(padding->bottom, rect->h, 0);
  int left = GTLD_UnitToPX(padding->left, rect->w, 0);

  return (GTLD_Rect){
    .x = rect->x + left,
    .y = rect->y + top,
    .w = rect->w - left - right,
    .h = rect->h - top - bottom};
}
