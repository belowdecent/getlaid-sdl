/**
 * \file getlaid-axis.h
 *
 * One dimensional container for layouts
 */

#ifndef __GTLD_AXIS
#define __GTLD_AXIS

#include <getlaid-units.h>

/** Possible alignments for the GTLD_Axis */
typedef enum GTLD_Alignment {
  /** Pack items from the start, similar to `align-items:
     start` in CSS */
  GTLD_ALIGN_BEGIN,
  /** Pack items around the center, similar to `align-items:
     center` in CSS */
  GTLD_ALIGN_CENTER,
  /** Pack items from the end, similar to `align-items: end`
     in CSS */
  GTLD_ALIGN_END
} GTLD_Alignment;

/**
 * Struct for defining layouts along one of the axes in
 * container
 *
 * \see GTLD_Alignment
 * \see GTLD_Unit
 */
typedef struct GTLD_Axis {
  GTLD_Alignment alignment; /**< Alignment of this axis */
  int count;                /**< Size of the layout array */

  /** Array of GTLD_Units that define the element sizes
   * along this axis */
  const GTLD_Unit* layout;
} GTLD_Axis;

/**
 * Sets a new layout for the given axis
 *
 * \param[out] axis Target axis for the layout
 * \param count Size of the layout
 * \param layout Layout to set
 *
 * \returns 0 on success, 1 if axis is NULL
 */
int GTLD_SetAxis(
  GTLD_Axis* axis, int count, const GTLD_Unit* layout
);

extern const GTLD_Axis GTLD_AUTOAXIS;

#endif
