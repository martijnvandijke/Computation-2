/*
 * lib-src/ansi/signal/signal.c
 * ISO 9899-1990, Section 7.7.1.1.
 *
 * void (*signal(int sig, void (*func)(int)))(int)
 * Register a signal handler.
 *
 * In a typical implementation, signal() is a system call.
 * Here we implement it as a library function instead,
 * registering the signal handler in global _sig_handler[].
 */

#include <signal.h>
#include <errno.h>


void
(*signal(int sig, void (*func)(int)))(int)
{
	register void (*old_sig)(int);
	static void	(**sig_handler)(int);

	if (sig < 0 || sig > _NSIG) {
		errno = EINVAL;			/* invalid argument */
		return SIG_ERR;			/* return error */
	}
	
	old_sig = sig_handler[sig];
	sig_handler[sig] = func;
	return old_sig;				/* return old handler */

}
