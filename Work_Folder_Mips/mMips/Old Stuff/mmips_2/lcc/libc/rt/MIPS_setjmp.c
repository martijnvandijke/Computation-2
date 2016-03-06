#include <setjmp.h>
#include <assert.h>

void
longjmp (env, val)
	jmp_buf env;
	int val;
{
	assert(0);
}

int
setjmp (jmp_buf env)
{
	assert(0);
  
	return 0;
}
