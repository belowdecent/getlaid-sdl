#include <getlaid-container.h>
#include <stdlib.h>

#include "getlaid-axis.h"

GTLD_Container* GTLD_AutoContainer(GTLD_Direction direction
) {
  GTLD_Container* c = malloc(sizeof(GTLD_Container));
  *c = (GTLD_Container){
    .direction = direction,
    .main = GTLD_AutoAxis(),
    .cross = GTLD_AutoAxis(),
    .repeat = GTLD_REPEAT_LAST};

  return c;
}
