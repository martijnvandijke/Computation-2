/*
 * lib-src/ansi/time/difftime.c
 * ANSI/ISO 9899-1990, Section 7.12.2.2.
 *
 * double difftime(time_t time1, time_t time0)
 */

#include <time.h>

double
difftime(time_t time1, time_t time0)
{
	return (double)(time1 - time0);
}
