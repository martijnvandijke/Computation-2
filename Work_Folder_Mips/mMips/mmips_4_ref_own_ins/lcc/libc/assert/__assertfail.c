/*
 * __assertfail: used by <assert.h>
 */

#include <stdio.h>
#include <assert.h>

void
__assertfail(char *__msg, char *__cond, char *__file, int __line)
{
        fprintf(stderr, __msg, __cond, __file, __line);

	abort();
}

