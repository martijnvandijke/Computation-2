/*
 * libc/time/asctime.c
 * ANSI/ISO 9899-1990, Section 7.12.3.1.
 *
 * char *asctime(const struct tm *timeptr)
 */

#include <stdio.h>
#include <time.h>
#include "tzfile.h"

/*
** A la X3J11, with core dump avoidance.
*/
char *
asctime(const struct tm *timeptr)
{
	static const char	wday_name[DAYSPERWEEK][3] = {
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	};
	static const char	mon_name[MONSPERYEAR][3] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	static char result[26];
	register const char *	wn;
	register const char *	mn;

	if (timeptr->tm_wday < 0 || timeptr->tm_wday >= DAYSPERWEEK)
		wn = "???";
	else
		wn = wday_name[timeptr->tm_wday];
	if (timeptr->tm_mon < 0 || timeptr->tm_mon >= MONSPERYEAR)
		mn = "???";
	else
		mn = mon_name[timeptr->tm_mon];
	(void) sprintf(result, "%.3s %.3s%3d %02.2d:%02.2d:%02.2d %d\n",
			wn, mn,
			timeptr->tm_mday, timeptr->tm_hour,
			timeptr->tm_min, timeptr->tm_sec,
			TM_YEAR_BASE + timeptr->tm_year);
	return result;
}

/* end of libc/time/asctime.c */
