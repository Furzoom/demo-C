#ifndef __ERROR_H
#define __ERROR_H

/* Nonfatal error related system call.
 * Print message and return.
 **/
void err_ret(const char *fmt, ...);

/* Fatal error related to system call.
 * Print message and terminate.
 **/
void err_sys(const char *fmt, ...);

/* Fatal error related to system call.
 * Print message, dump core, and terminate. 
 **/
void err_dump(const char *fmt, ...);

/* Nonfatal error unrelated to system call.
 * Print message and return.
 **/
void err_msg(const char *fmt, ...);

/* Fatal error unrelated to system call.
 * Print message and terminate.
 **/
void err_quit(const char *fmt, ...);
#endif // __ERROR_H
