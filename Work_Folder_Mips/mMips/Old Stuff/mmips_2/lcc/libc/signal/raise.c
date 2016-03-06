/*
 * libc/signal/raise.c
 * ISO 9899-1990, Section 7.7.2.1.
 *
 * int raise(int sig)
 *
 * In a typical implementation, signal() is a system call
 * and raise() just does kill(getpid(), sig).
 * Here we do not use kill().
 * The default action for any signal is to ignore it (same as SIG_IGN),
 * except that the default action for SIGABRT is
 * to print a message to standard error and then to invoke _exit().
 */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int
raise(int sig)
{
	static void	(**sig_handler)(int);
	register void (*func)(int);

	if (sig < 0 || sig > _NSIG)
		return -1;			/* bad signal number, fail */
	
	func = sig_handler[sig];		/* current handler */
	if (func == SIG_IGN)
		return 0;			/* ignore successfully */
	else if (func == SIG_DFL) {
		if (sig == SIGABRT) {
			write(2, "\nAbort\n", 7);
			exit(EXIT_FAILURE);	/* _exit with failure status */
		}
		return 0;			/* else ignore is default for now */
	} else {
		sig_handler[sig] = SIG_DFL;	/* restore default */
		(*func)(sig);			/* execute handler */
	}
	return 0;				/* return success */
}

/* end of libc/signal/raise.c */
