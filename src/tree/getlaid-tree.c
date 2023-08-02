#include <getlaid-tree.h>

GTLD_Element* GTLD_AddChildToElement(
  GTLD_Element* parent, GTLD_Element child
) {
  if (parent == NULL)
    return NULL;

  if (parent->capacity <= parent->count) {
    parent->capacity =
      (parent->capacity > 0) ? parent->capacity * 3 / 2 : 2;

    GTLD_Element* tmp = reallocarray(
      parent->children, parent->capacity,
      sizeof(GTLD_Element)
    );

    if (tmp == NULL) {
      fprintf(
        stderr, "couldn't resize element(%i) children",
        parent->id
      );
      exit(1);
    }

    parent->children = tmp;
  }

  parent->children[parent->count] = child;
  return &(parent->children[parent->count]);
};
