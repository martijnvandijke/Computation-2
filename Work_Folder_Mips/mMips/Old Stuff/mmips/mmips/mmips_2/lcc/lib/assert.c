#include <stdio.h>
#include <stdlib.h>

static char rcsid[] = "$Id: assert.c,v 1.1 1995/07/25 20:34:24 cwf Exp $";

int _assert(char *e, char *file, int line) {
	fprintf(stderr, "assertion failed:");
	if (e)
		fprintf(stderr, " %s", e);
	if (file)
		fprintf(stderr, " file %s", file);
	fprintf(stderr, " line %d\n", line);
	abort();
	return 0;
}
