#include "state.h"
#include "display.h"

struct state make_state()
{
	struct state s = {
		//.next_display = display_start,
		.A = 0
	};
	return s;
}
