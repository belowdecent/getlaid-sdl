/** \file getlaid-tree.h
 * GTLD_Element creation and manipulation
 */

#ifndef __GTLD_TREE
#define __GTLD_TREE

#include <getlaid-element.h>

/**
 * A tree of GTLD_Elements, additionally manages ids of
 * newly created elements
 *
 * \see GTLD_Element
 */
typedef struct GTLD_Tree {
  /** Root element of the tree */
  GTLD_Element* root;

  /** The last id assigned to an element */
  int last_id;

  /** Ids that have been freed after deletion of elements in
   * the tree */
  int* free_ids;

  /** Capacity of the free_ids dynamic array */
  int free_ids_capacity;
  /** Amount of ids stored in the free_ids */
  int free_ids_count;
} GTLD_Tree;

/**
 * Creates a tree with element as the root
 *
 * \param[in] element Root of the tree, if NULL a new
 * element created with id of 0
 *
 * \returns a GTLD_Tree struct
 */
GTLD_Tree GTLD_CreateTree(GTLD_Element* element);

/**
 * Creates a new element within a tree with given parameters
 *
 * \param[out] tree Tree in which element should be created
 * \param[out] parent Element, to which children
 *                     created element will be appended
 *                     or NULL to create an orphan
 * \param[in] bounds Bounds of the created element
 * \param[in] padding Padding of the created element
 * \param[in] container Container of the created element
 *
 * \returns A pointer to a newly created element
 */
GTLD_Element* GTLD_CreateElement(
  GTLD_Tree* tree, GTLD_Element* parent, GTLD_Rect* bounds,
  GTLD_Padding* padding, GTLD_Container* container
);

/**
 * Inserts orphan element into parent elements children,
 * the function does not ensure orphanness of the passed
 * element
 *
 * \param[out] parent Element into which orphan element is
 * inserted
 * \param[in] orphan Element which is inserted to
 * parent's children
 *
 * \returns
 * 0, if adoption was successful
 * 1,
 */
int GTLD_AdoptOrphanElement(
  GTLD_Element* parent, GTLD_Element* orphan, int position
);

#endif
