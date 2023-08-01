#include <assert.h>
#include <getlaid-sdl.h>

int main(void) {
	const GTLD_Container cont = GTLD_AUTOCONTAINER(GTLD_ROW, GTLD_ALIGN_BEGIN, GTLD_ALIGN_BEGIN);
	const GTLD_Container cont2 = GTLD_AUTOCONTAINER(GTLD_COLUMN, GTLD_ALIGN_CENTER, GTLD_ALIGN_END);

	assert(cont.main.layout == cont.cross.layout);
	assert(cont.main.layout == cont2.main.layout);
	assert(cont.main.layout == cont2.cross.layout);

	return 0;
}
