/*
 * lib-src/ansi/string/strerror.c
 * ANSI/ISO 9899-1990, Section 7.11.6.2.
 *
 * char *strerror(int errnum)
 * Format an error message string.
 */

#include <string.h>
#include <stdio.h>
#include <errno.h>

char *
strerror(int errnum)
{
	static char buf[_STRERROR_MAX];

	if ((unsigned)errnum < _sys_nerr)
		return (char *)_sys_errlist[errnum];

	(void) sprintf(buf, (char *)_sys_errformat, errnum);
	return buf;
}
