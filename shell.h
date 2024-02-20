#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;
extern char *__progname;
void simple_shell(char *av);
char **token_array(char *buffer);
int check_line(char *buffer);
void environment(void);
char *find_path(char *buffer);
void show_prompt(void);
void execute(char *paras[]);
void str_tok(char *buffer, char *array[]);
void remove_spaces(char *state);
ssize_t my_getline(char **lineptr, size_t *n, FILE *ss);
void vec(void);
void my_exit(char *buff, char *num);
int cd_command(char *path);
#endif
