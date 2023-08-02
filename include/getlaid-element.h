/**
 * \file getlaid-element.h
 *
 * Core GetLaid object for creating layouts
 */

#ifndef __GTLD_ELEMENT
#define __GTLD_ELEMENT

#include <SDL_pixels.h>
#include <getlaid-container.h>
#include <getlaid-padding.h>

/**
 * An element tree node containing all of
 * the information for dynamically creating layouts.
 */
typedef struct GTLD_Element {
  int id; /**< will be used to bind outside data to the tree
           */

  GTLD_Rect* bounds; /**< Bounds of the element, which are
                       influenced by the parent layout */
  const GTLD_Padding*
    padding; /**< Inner padding, influences
         bounds of children elements */
  const GTLD_Container*
    container; /**< Container, defines the layout of the
                  element children */
  struct GTLD_Element*
    children; /**< Dynamic array of children of the element
               */
  int
    capacity; /**< Current max size of the children array */
  int count;  /**< Current children count */
} GTLD_Element;

/**
 * Create a list of rects from the layout to apply to
 * children.
 *
 * \returns a array of child_count GTLD_Rects
 */
GTLD_Rect* GTLD_GetChildrenBounds(
  const GTLD_Container* container,
  const GTLD_Rect* parent_rect, int child_count
);

#endif
