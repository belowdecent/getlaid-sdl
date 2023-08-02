#include <assert.h>
#include <getlaid-sdl.h>

int main(void) {
  const GTLD_Container cont = GTLD_AUTOCONTAINER(GTLD_ROW);
  const GTLD_Container cont2 =
    GTLD_AUTOCONTAINER(GTLD_COLUMN);

  assert(cont.main.layout == cont.cross.layout);
  assert(cont.main.layout == cont2.main.layout);
  assert(cont.main.layout == cont2.cross.layout);

  return 0;
}
