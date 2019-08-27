#include "utils.h"

void WaitClocks(clock_t t)
{
	clock_t s;

	s = clock();
	while (clock() - s < t)
		continue;
}