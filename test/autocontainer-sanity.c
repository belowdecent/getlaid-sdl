#include <assert.h>
#include <getlaid-sdl.h>

#include "getlaid-container.h"

int main(void) {
  const GTLD_Container* cont = GTLD_AutoContainer(GTLD_ROW);
  const GTLD_Container* cont2 =
    GTLD_AutoContainer(GTLD_COLUMN);

  assert(
    cont->main->layout[0].unit ==
    cont->cross->layout[0].unit
  );
  assert(
    cont->main->layout[0].unit ==
    cont2->main->layout[0].unit
  );
  assert(
    cont->main->layout[0].unit ==
    cont2->cross->layout[0].unit
  );

  return 0;
}
