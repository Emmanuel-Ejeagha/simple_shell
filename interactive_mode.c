#include "main.h"

#define MAX_ARGS 10

/**
 * tokenize_command - This tokenizes our cmd
 * @command: command to be tokenized
 * @args: the argument size
 *
 * Return: (0)
 */
void tokenize_command(char *command, char *args[])
{
	char *token = strtok(command, " ");
	int i = 0;

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;
}

/**
 * execute_command - Works out interactive mode
 *	commands
 * @args: the argument size
 *
 * Return: (void)
 */
void execute_command(char *args[])
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{

		if (my_execvp(args[0], args) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
		}
	}
}

