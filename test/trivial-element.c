#include <assert.h>
#include <getlaid-sdl.h>
#include <stdio.h>
#include <stdlib.h>

#include "getlaid-axis.h"
#include "getlaid-container.h"
#include "getlaid-element.h"
#include "getlaid-rect.h"

#define PARENT_X 20
#define PARENT_Y 10
#define PARENT_W 100
#define PARENT_H 100

void print_assert(
  const char* fmt, int child_index, int value, int expected
) {
  printf(fmt, child_index, value, expected);
  assert(value == expected);
}

int main() {
  GTLD_Rect rect = {
    .x = PARENT_X,
    .y = PARENT_Y,
    .w = PARENT_W,
    .h = PARENT_H};
  GTLD_Element el = {
    .count = 2,
    .children = malloc(sizeof(GTLD_Element) * 2),
    .bounds = &rect,
    .container = &GTLD_AUTOROW};

  el.children[0] = (GTLD_Element){0};
  el.children[1] = (GTLD_Element){0};

  GTLD_Rect* rects =
    GTLD_GetChildrenBounds(el.container, el.bounds, 2);

  for (int i = 0; i < el.count; ++i) {
    el.children[i].bounds = &rects[i];
  }

  free(rects);

  for (int i = 0; i < el.count; ++i) {
    print_assert(
      "Child %i width: %i. Expected: %i\n", i,
      el.children[i].bounds->w, PARENT_W / 2
    );

    print_assert(
      "Child %i height: %i. Expected: %i\n", i,
      el.children[i].bounds->h, PARENT_H
    );

    print_assert(
      "Child %i y: %i. Expected: %i\n", i,
      el.children[i].bounds->y, PARENT_Y
    );
  }

  print_assert(
    "Child %i x: %i. Expected: %i\n", 0,
    el.children[0].bounds->x, PARENT_X
  );
  print_assert(
    "Child %i x: %i. Expected: %i\n", 1,
    el.children[1].bounds->x, PARENT_X + PARENT_W / 2
  );

  return 0;
}
