/*
 * lib-src/ansi/stdio/perror.c
 * ANSI/ISO 9899-1990, Section 7.9.10.4.
 *
 * void perror(const char *s)
 * Print an error message to the standard error stream.
 */

#include <stdio.h>
#include <errno.h>
#include "shared_libc.h"

void
perror(const char *s)
{
	if (s != NULL && *s != 0) {
		fputs(s, stderr);
		fputs(": ", stderr);
	}
	if ((unsigned)errno < _sys_nerr)
		fputs((char *)_sys_errlist[errno], stderr);
	else
		fprintf(stderr, (char *)_sys_errformat, errno);
	fputc('\n', stderr);
}
