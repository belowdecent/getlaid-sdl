/**
 * \file getlaid-units.h
 *
 * Relative and absolute units to use in layouts
 */

#ifndef __GTLD_UNITS
#define __GTLD_UNITS

/** Possible unit types for GTLD_Unit */
typedef enum GTLD_UnitType {
  /** Raw pixel size */
  GTLD_UNIT_PX,

  /**
   * Size relative to a container, where
   * "1.0" is 100% of the container height/width
   */
  GTLD_UNIT_PERCENT,

  /**
   * Special unit type, all of the GTLD_UNIT_AUTO
   * sized units fill the remaining space in the container
   * evenly
   */
  GTLD_UNIT_AUTO
} GTLD_UnitType;

/**
 * Unit struct for using absolute and relative units
 */
typedef struct GTLD_Unit {
  GTLD_UnitType unit;
  float value;
} GTLD_Unit;

/**
 * Converts GTLD_Units to pixel units
 *
 * \param unit unit to convert
 * \param container_size size in pixels of the container,
 * which is used to evaluate percent units \param auto_size
 * size in pixels to assign to auto_units
 */
int GTLD_UnitToPX(
  GTLD_Unit unit, int container_size, int auto_size
);

/**
 * GTLD_Axis uses pointers to GTLD_Units as layout, this
 * constant is created to minimize creation of the same
 * auto-layouts
 */
extern const GTLD_Unit GTLD_AUTOSIZE;

#endif
