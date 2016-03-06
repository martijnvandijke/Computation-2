/*
 * libc/stdlib/calloc.c
 * ANSI/ISO 9899-1990, Section 7.10.3.1.
 *
 * void *calloc(size_t nmemb, size_t size)
 * Allocate and zero memory.
 */

#include <stdlib.h>

void *
calloc(size_t nmemb, size_t size)
{
	register void *s;

	size *= nmemb;
	if ((s = malloc(size)) != NULL)
		memset(s, 0, size);
	return s;
}

/* end of calloc.c */

