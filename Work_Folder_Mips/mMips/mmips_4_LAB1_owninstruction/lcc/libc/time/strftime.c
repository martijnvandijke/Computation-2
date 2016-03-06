/*
 * lib-src/ansi/time/strftime.c
 * ANSI/ISO 9899-1990, Section 7.12.3.5.
 *
 * size_t strftime(char *s, size_t maxsize, const char *format, const struct tm *timeptr)
 * Print a formatted time string.
 *
 * This supports only the "C" locale at present.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "tzfile.h"

#define	NBUF	128			/* conversion buffer size */

extern char *__tzname[2];		/* time zone names */

/* The string constants below should be changeable via setlocale(LC_TIME, ...). */
static	char	*short_weekdays[] =
{
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
};
static	char	*long_weekdays[] =
{
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
	"Saturday",
};
static	char	*short_monthnames[] =
{
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
	"Oct", "Nov", "Dec",
};
static	char	*long_monthnames[] = {
	"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December",
};
static	char	am_name[] = "AM";
static	char	pm_name[] = "PM";

size_t
strftime(char *s, size_t maxsize, const char *format, const struct tm *timeptr)
{
	register size_t count;		/* output character count */
	register int charlen, len, field;
	char tbuf[NBUF];
	char mbc[MB_CUR_MAX];		/* assumes MB_CUR_MAX is constant */
	enum { ordinary, after_percent } state;
	wchar_t wc;
	char *s1;

	for (state = ordinary, count = 0; count < maxsize; )
	{
		charlen = mbtowc(&wc, format, MB_CUR_MAX);
		if (charlen < 0)	/* invalid multibyte char */
			return 0;
		format += charlen;

		switch (state) {

		case ordinary:
			if (wc == '%')
				state = after_percent;
			else {
append:				/* Append wc to output string. */
				charlen = wctomb(mbc, wc);
				if (charlen <= 0 || count + charlen >= maxsize)
					return 0;
				memcpy(&s[count], mbc, (size_t)charlen);
				if (wc == 0)
					return count;	/* end of string */
				count += charlen;
			}
			continue;

		case after_percent:
			state = ordinary;
			len = 0;		/* field length for numeric formats */
			s1 = NULL;
			tbuf[0] = 0;

			/* Cases 0 and default below are undefined behavior. */
			switch(wc) {
			case 0:
				return count;	/* unexpected end of string e.g. "%" */
			default:
			case '%':
				goto append;
			case 'a':
				s1 = short_weekdays[timeptr->tm_wday];
				break;
			case 'A':
				s1 = long_weekdays[timeptr->tm_wday];
				break;
			case 'b':
				s1 = short_monthnames[timeptr->tm_mon];
				break;
			case 'B':
				s1 = long_monthnames[timeptr->tm_mon];
				break;
			case 'c':
				/* __tzset(); */
				s1 = asctime(timeptr);
				s1[24] = 0;	/* zap trailing '\n' */
				break;
			case 'd':
				field = timeptr->tm_mday;
				len = 2;
				break;
			case 'H':
				field = timeptr->tm_hour;
				len = 2;
				break;
			case 'I':
				field = timeptr->tm_hour;
				field %= 12;
				if (field == 0)
					 field = 12;
				len = 2;
				break;
			case 'j':
				field = timeptr->tm_yday + 1;
				len = 3;
				break;
			case 'm':
				field = timeptr->tm_mon + 1;
				len = 2;
				break;
			case 'M':
				field = timeptr->tm_min;
				len = 2;
				break;
			case 'p':
				if (timeptr->tm_hour >= 12)
					s1 = pm_name;
				else
					s1 = am_name;
				break;
			case 'S':
				field = timeptr->tm_sec;
				len = 2;
				break;
			case 'U':
				field = (timeptr->tm_yday + 7 - timeptr->tm_wday)/7;
				len = 2;
				break;
			case 'w':
				field = timeptr->tm_wday;
				len = 1;
				break;
			case 'W':
				field = (timeptr->tm_yday + 7 - (timeptr->tm_wday ? (timeptr->tm_wday - 1) : 6))/7;
				len = 2;
				break;
			case 'x':
				sprintf(tbuf,"%s %s %02d, %04d",
					short_weekdays[timeptr->tm_wday],
					short_monthnames[timeptr->tm_wday],
					timeptr->tm_mday,
					timeptr->tm_year);
				s1 = tbuf;
				break;
			case 'X':
				sprintf(tbuf,"%02d:%02d:%02d",
					timeptr->tm_hour,
					timeptr->tm_min,
					timeptr->tm_sec);
				s1 = tbuf;
				break;
			case 'y':
				field = (timeptr->tm_year + TM_YEAR_BASE) % 100;
				len = 2;
				break;
			case 'Y':
				field = timeptr->tm_year + TM_YEAR_BASE;
				len = 4;
				break;
			case 'Z':
				__tzset();	/* set up __tzname */
				if (timeptr->tm_isdst == 0 || timeptr->tm_isdst == 1)
					s1 = __tzname[timeptr->tm_isdst];
				break;
			}

			if (len) {
				/* Format the number in field with given length. */
				sprintf(tbuf, "%0*d", len, field);
				s1 = tbuf;
				/* and fall thru to print it... */
			}
			if (s1) {
				/* Print the string in s1. */
				for (;;) {
					/* Pick up a multibyte char from the string */
					charlen = mbtowc(&wc, s1, MB_CUR_MAX);
					if (charlen == 0)	/* end of string */
						break;
#if	defined(sparc)
					/* Avoid mbtowc() bug in Sparc library... */
					if (wc == 0)
						break;
#endif
					if (charlen < 0)	/* invalid multibyte char */
						return 0;
					s1 += charlen;

					/* Append wc to the output string. */
					charlen = wctomb(mbc, wc);
					if (charlen <= 0 || count + charlen >= maxsize)
						return 0;
					memcpy(&s[count], mbc, (size_t)charlen);
					count += charlen;
				}
			}
		}
	}
	return 0;		       /* string overflow */
}
