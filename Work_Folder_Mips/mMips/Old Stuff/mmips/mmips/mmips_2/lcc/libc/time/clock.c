/*
 * libc/time/clock.c
 * N.B. This assumes 100 MHz clock for now,
 * it should probably be tweaked to read PPL registers and scale accordingly.
 */

#include <time.h>

time_t
clock(void)
{
	abort();

	return 0;
}

/* end of libc/time/clock.c */
