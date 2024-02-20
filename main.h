#ifndef _MAIN_H_
#define _MAIN_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <ctype.h>
#include <signal.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/wait.h>

extern char **environ;

/* my_strncmp*/
int custom_strncmp(const char *str1, const char *str2, size_t n);

/* main.c*/
int interactive_mode(void);
int non_interactive_mode(void);

/* interactive_mode.c */
void execute_command(char *args[]);
void tokenize_command(char *command, char *args[]);

/* strings_control.c */
void display_chars(const char *format, ...);
void my_putchar(char c);
size_t my_strcspn(const char *str1, const char *str2);
char *my_strchr(const char *str, int c);

/* strings_control2.c*/
int my_strcmp(const char *str1, const char *str2);
int my_strcmp2(const char *strx, const char *stry);
char *my_strdup(const char *src);
size_t my_strlen(const char *str);

/* strings_control2.c*/
void my_strcpy(char *destination, const char *source);

/*my_functions.c*/
int my_execvp(const char *file, char *const argv[]);
int my_strncmp(const char *str1, const char *str2, size_t n);
int my_snprintf(char *str, size_t size, const char *format, ...);
int my_vsnprintf_init(char *, size_t, const char *, va_list);

/* getenv.c*/
char *my_getenv(const char *name);

/* non_interactive_mode.c*/
void execute_non_interactive(char *command);

/* signal_handler.c*/
void ctrl_c(int signum);

/* the_vsprintf_env.c*/
int my_vsnprintf(char *, size_t, const char *,
		va_list, size_t, size_t, char *);

#endif
