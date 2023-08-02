#include <getlaid-tree.h>
#include <stdlib.h>

#include "getlaid-container.h"
#include "getlaid-element.h"

GTLD_Tree GTLD_CreateTree(GTLD_Element* element) {
  if (element == NULL) {
    element = malloc(sizeof(GTLD_Element));
    *element = (GTLD_Element){
      .container = GTLD_AUTOCONTAINER(GTLD_ROW),
    };
  }

  return (GTLD_Tree){
    .root = element, .last_id = element->id};
}

GTLD_Element* GTLD_CreateElement(
  GTLD_Tree* tree, GTLD_Element* parent, GTLD_Rect bounds,
  GTLD_Padding padding, GTLD_Container container
) {
  if (tree == NULL)
    return NULL;
  int id;

  if (tree->free_ids_count) {
    --tree->free_ids_count;
    id = tree->free_ids[tree->free_ids_count];
  } else {
    ++tree->last_id;
    id = tree->last_id;
  }

  GTLD_Element* element = malloc(sizeof(GTLD_Element));
  *element = (GTLD_Element){
    .id = id,
    .bounds = bounds,
    .padding = padding,
    .container = container,
  };

  if (parent) {
    GTLD_AdoptOrphanElement(parent, element, -1);
    return &parent->children[parent->count - 1];
  }

  return element;
}

int GTLD_AdoptOrphanElement(
  GTLD_Element* parent, GTLD_Element* orphan, int position
) {
  if (parent == NULL)
    return 1;
  if (orphan == NULL)
    return 2;

  if (parent->capacity <= parent->count) {
    parent->capacity =
      (parent->capacity > 0) ? parent->capacity * 3 / 2 : 2;

    GTLD_Element* tmp = reallocarray(
      parent->children, parent->capacity,
      sizeof(GTLD_Element)
    );

    if (tmp == NULL)
      return 3;

    parent->children = tmp;
  }

  int last_index = parent->count;
  ++parent->count;

  if (position < 0 || position >= last_index) {
    parent->children[last_index] = *orphan;
  } else {
    for (int i = last_index; i > position; --i) {
      parent->children[i] = parent->children[i - 1];
    }

    parent->children[position] = *orphan;
  }

  free(orphan);
  return 0;
}
