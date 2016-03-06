/*
 * lib-src/ansi/errno/_sys_errlist.c
 * Global information for use by perror() and strerror().
 *
 * const char _sys_errformat[];
 * const char *_sys_errlist[];
 * const unsigned _sys_nerr;
 */

#include <errno.h>

/*
 * This list should correspond to the errno values defined in <errno.h>.
 * Descriptions here correspond to the short names in Posix.1, section 2.4.
 */
const	char		*_sys_errlist[] = {
	"[No error]",				/* 0		*/
 	"Operation not permitted",		/* EPERM	*/
 	"No such file or directory",		/* ENOENT	*/
 	"No such process",			/* ERSCH	*/
	"Interrupted function call",		/* EINTR	*/
	"Input/output error",			/* EEIO		*/
 	"No such device or address",		/* ENXIO	*/
 	"Arg list too long",			/* E2BIG	*/
 	"Exec format error",			/* ENOEXEC	*/
 	"Bad file descriptor",			/* EBADF	*/
	"No child processes",			/* ECHILD	*/
	"Resource temporarily unavailable",	/* EAGAIN	*/
	"Not enough space",			/* ENOMEM	*/
	"Permission denied",			/* EACCES	*/
	"Bad address",				/* EFAULT	*/
	"Block device required",		/* ENOTBLK	*/
	"Resource busy",			/* EBUSY	*/
	"File exists",				/* EEXIST	*/
	"Improper link",			/* EXDEV	*/
	"No such device",			/* ENODEV	*/
	"Not a directory",			/* ENOTDIR	*/
	"Is a directory",			/* EISDIR	*/
	"Invalid argument",			/* EINVAL	*/
	"Too many open files in system",	/* ENFILE	*/
	"Too many open files",			/* EMFILE	*/
	"Inappropriate I/O control operation",	/* ENOTTY	*/
	"Text file busy",			/* ETXTBSY	*/
	"File too large",			/* EFBIG	*/
	"No space left on device",		/* ENOSPC	*/
	"Invalid seek",				/* ESPIPE	*/
	"Read-only file system",		/* EROFS	*/
	"Too many links",			/* EMLINK	*/
	"Broken pipe",				/* EPIPE	*/
	"Domain error",				/* EDOM		*/
	"Result too large",			/* ERANGE	*/
	"Filename too long",			/* ENAMETOOLONG	*/
	"Resource deadlock avoided"		/* EDEADLK	*/
	"No locks available", 			/* ENOLCK	*/
	"Directory not empty",			/* ENOTEMPTY	*/
	"Function not implemented",		/* ENOSYS	*/
};

const	unsigned int	_sys_nerr = (sizeof _sys_errlist)/(sizeof _sys_errlist[0]);

/*
 * N.B. string/strerror.c assumes result formatted by _sys_errformat
 * will fit in _STRERROR_MAX byte buffer.
 */
const	char		_sys_errformat[] = "Error %d";

/* end of _sys_errlist.c */
