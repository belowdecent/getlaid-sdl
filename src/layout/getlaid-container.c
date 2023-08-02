#include <getlaid-container.h>

const GTLD_Container GTLD_AUTOROW = {
  .main = &GTLD_AUTOAXIS,
  .cross = &GTLD_AUTOAXIS,
  .direction = GTLD_ROW,
  .repeat = GTLD_REPEAT_LAST};

const GTLD_Container GTLD_AUTOCOLUMN = {
  .main = &GTLD_AUTOAXIS,
  .cross = &GTLD_AUTOAXIS,
  .direction = GTLD_COLUMN,
  .repeat = GTLD_REPEAT_LAST};
