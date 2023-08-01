#ifndef __GTLD_PADDING
#define __GTLD_PADDING

#include <getlaid-rect.h>
#include <getlaid-units.h>

typedef struct GTLD_Padding {
  GTLD_Unit top;
  GTLD_Unit right;
  GTLD_Unit bottom;
  GTLD_Unit left;
} GTLD_Padding;

GTLD_Rect GTLD_PadBounds(
  GTLD_Rect rect, GTLD_Padding padding
);

#define GTLD_PADDING_ALL(unit, value)              \
  (GTLD_Padding) {                                 \
    {unit, value}, {unit, value}, {unit, value}, { \
      unit, value                                  \
    }                                              \
  }

#define GTLD_PADDING_INLINE(unit, value)     \
  (GTLD_Padding) {                           \
    {0}, {unit, value}, {0}, { unit, value } \
  }

#define GTLD_PADDING_BLOCK(unit, value)      \
  (GTLD_Padding) {                           \
    {unit, value}, {0}, {unit, value}, { 0 } \
  }

#endif
