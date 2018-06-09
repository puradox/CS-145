#include "state.h"


struct state make_state()
{
	struct state s = {
		.key_A = false,
		.row1 = {'a', 'b', 'c', 'd', 'e', 'f', 'e', 'a', 'b', 'c', 'd', 'e', 'f', 'e', 'f', 'e'},
		.row2 = {'z', 'x', 'y', 'v', 't', 's', 'r', 'a', 'b', 'c', 'd', 'e', 'f', 'e', 'f', 'e'}
	};
	return s;
}
