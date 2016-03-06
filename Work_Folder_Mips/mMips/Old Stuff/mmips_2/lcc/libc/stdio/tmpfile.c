/*
 * Copyright (c) 1990 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <sys/syslimits.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

FILE *tmpfile(void)
{
	FILE *fp;
	int e;
	char *f, buf[PATH_MAX];

	if ((f = tmpnam(buf)) == NULL)
		return (NULL);
	fp = fopen(f, "wb+");
	e = errno;
	(void) _unlink(f);
	errno = e;
	return fp;
}
