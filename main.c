#include "shell.h"
#define BUFFER 1024

/**
 * show_prompt - it displays prompt to user
 */
void show_prompt(void)
{
	printf("$ ");
}

/**
 * str_tok - string token
 * @buffer: its buffer of astring
 * @array: array to string
 */
void str_tok(char *buffer, char *array[])
{
	char *token;
	char *arr[100];
	int i = 0, j;

	if (!buffer)
		return;
	token = strtok(buffer, " \n");
	while (token)
	{
		arr[i++] = token;
		token = strtok(NULL, " \n");
	}
	for (j = 0; j < i; j++)
	{
		array[j] = arr[j];
	}
	array[j] = NULL;
}

/**
 * execute - it executes the function
 * @paras: input array
 */
void execute(char *paras[])
{
	pid_t pid;
	struct stat st;

	if (stat(paras[0], &st) != 0)
	{
		perror(__progname);
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		perror(__progname);
		exit(2);
	}
	else if (pid == 0)
	{
		execve(paras[0], paras, environ);
		perror(__progname);
		exit(2);
	}
	else
		waitpid(pid, NULL, 0);
}

/**
 * main - entry point
 * Return: return 0.
 */
int main(void)
{
	char *buffer = NULL, *args[100];
	char cmd[] = "/bin/ls";
	size_t n;

	while (1)
	{
		if (isatty(0))
			show_prompt();
		if (getline(&buffer, &n, stdin) == -1)
		{
			free(buffer);
			break;
		}
		buffer[strlen(buffer)] = '\0';
		str_tok(buffer, args);
		if (strcmp(args[0], "cd") == 0)
			printf("%s\n", buffer);
		if (strcmp(args[0], "ls") == 0)
			args[0] = cmd;
		remove_spaces(args[0]);
		if (strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			break;
		}
		if (strcmp(args[0], "env") == 0)
		{
			vec();
			continue;
		}
		execute(args);
	}

	return (0);
}
