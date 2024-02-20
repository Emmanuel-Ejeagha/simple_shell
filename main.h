#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


#define MAX_ARGS 10
#define BUFF_SIZE 1024

void tokenize_str(const char *str, char *str_arr[], int max);
char *_strcpy(char *dest, const char *src);
int run_code(char **str_arr, char **envp, pid_t pid);
void _print_str(char *string);
char *find_the_path(char *command, char *path[]);
void print_env(char **env);
int _putchar(char c);
char *create_buff();
char *strdup_static(const char *str);
void remove_new_line(char *str);
char *initialize_path(char *path[], char *str_arr[]);

#endif
