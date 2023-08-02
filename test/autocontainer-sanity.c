#include <assert.h>
#include <getlaid-sdl.h>

int main(void) {
  const GTLD_Container cont = GTLD_AUTOROW;
  const GTLD_Container cont2 = GTLD_AUTOCOLUMN;

  assert(cont.main->layout == cont.cross->layout);
  assert(cont.main->layout == cont2.main->layout);
  assert(cont.main->layout == cont2.cross->layout);

  return 0;
}
