/**
 * \file getlaid-padding.h
 *
 * Inner padding for elements
 */

#ifndef __GTLD_PADDING
#define __GTLD_PADDING

#include <getlaid-rect.h>
#include <getlaid-units.h>

/**
 * Describes element padding in GTLD_Units, any
 * GTLD_Unit with GTLD_UNIT_AUTO type will be set to 0.
 */
typedef struct GTLD_Padding {
  GTLD_Unit top;
  GTLD_Unit right;
  GTLD_Unit bottom;
  GTLD_Unit left;
} GTLD_Padding;

/**
 * Creates a new GTLD_Rect shrunk by the padding.
 *
 * \param[in] rect Rect to shrink
 * \param[in] padding Padding to shrink by
 */
GTLD_Rect GTLD_PadBounds(
  const GTLD_Rect* rect, const GTLD_Padding* padding
);

/**
 * Create a padding, where all values are equal
 *
 * \param unit GTLD_UnitType of the padding
 * \param value Value of the padding
 */
#define GTLD_PADDING_ALL(unit, value)              \
  (GTLD_Padding) {                                 \
    {unit, value}, {unit, value}, {unit, value}, { \
      unit, value                                  \
    }                                              \
  }

/**
 * Create a padding with equal left and right values
 *
 * \param unit GTLD_UnitType of the padding
 * \param value Value of the padding
 */
#define GTLD_PADDING_INLINE(unit, value)     \
  (GTLD_Padding) {                           \
    {0}, {unit, value}, {0}, { unit, value } \
  }

/**
 * Create a padding with equal top and bottom values
 *
 * \param unit GTLD_UnitType of the padding
 * \param value Value of the padding
 */
#define GTLD_PADDING_BLOCK(unit, value)      \
  (GTLD_Padding) {                           \
    {unit, value}, {0}, {unit, value}, { 0 } \
  }

#endif
