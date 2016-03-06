/*
 * rename()
 * Rename old to new.
 */

#include <stdlib.h>
#include <unistd.h>

int
rename(const char *old, const char *new)
{
	if (_link(old, new) == -1 )
		return -1;
	return _unlink(old);
}
