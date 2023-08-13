/**
 * \file getlaid-container.h
 *
 * Two-dimensional container consisting of main and cross
 * axes, akin to CSS Flexbox
 */

#ifndef __GTLD_CONTAINER
#define __GTLD_CONTAINER

#include <getlaid-axis.h>

/** Growth direction for the GTLD_Container */
typedef enum GTLD_Direction {
  /** Main axis - horizontal, cross axis - vertical */
  GTLD_ROW,

  /** Main axis - vertical, cross axis - horizontal */
  GTLD_COLUMN
} GTLD_Direction;

/** Repeat mode for layouts, needs rework */
typedef enum GTLD_Repeat {
  GTLD_REPEAT_LAST,
  GTLD_REPEAT_CYCLE,
  GTLD_REPEAT_WRAP,
  GTLD_REPEAT_NONE,
} GTLD_Repeat;

/** Main object for defining layouts */
typedef struct GTLD_Container {
  GTLD_Direction
    direction; /**< Container growth direction */
  GTLD_Repeat
    repeat; /**< \todo make it a GTLD_Axis property */

  GTLD_Axis* main;  /**< main axis */
  GTLD_Axis* cross; /**< cross axis */
} GTLD_Container;

/** Helper function to create containers where children are
 * equally aligned */
GTLD_Container* GTLD_AutoContainer(GTLD_Direction direction
);

#endif
