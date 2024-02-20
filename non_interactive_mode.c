#include "main.h"

#define MAX_COMMAND_LENGTH 100

/**
 * execute_non_interactive - works out our
 * non interactive mode shell command
 * @command: passed in command
 *
 * Return: (void)
 */
void execute_non_interactive(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		char *args[MAX_COMMAND_LENGTH];
		char *token = strtok(command, " ");

		int i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;

		if (my_execvp(args[0], args) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

