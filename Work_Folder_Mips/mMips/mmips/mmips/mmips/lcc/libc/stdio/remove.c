/* remove.c */

#include <stdio.h>
#include <unistd.h>

int
remove(const char *filename)
{
	return _unlink(filename);
}
