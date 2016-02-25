/*
 * BSD wants to set a __cleanup vector to be called on exit(). We use the
 * exit in libgcc.a which calls _cleanup automatically to close files.
 */
void     (*__cleanup)();
