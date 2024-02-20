#include "main.h"

#define MAX_ARGS 10

/**
 * main - checks if shell is in interactive
 *	or non interactive mode
 *
 * Return: (EXIT_SUCCESS)
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		interactive_mode();
	}
	else
	{
		non_interactive_mode();
	}
	return (EXIT_SUCCESS);
}

/**
 * interactive_mode - The main interactive shell that
 *	prompts and accepts user input in a loop
 *
 * Return: (0)
 */
int interactive_mode(void)
{
	char *command = NULL;
	size_t command_size = 0;
	char *args[MAX_ARGS];

	while (1)
	{
		signal(SIGINT, ctrl_c);
		display_chars("$ ");

		if (getline(&command, &command_size, stdin) == -1)
		{
			display_chars("\n");
			break;
		}

		command[my_strcspn(command, "\n")] = '\0';

		tokenize_command(command, args);

		if (my_strncmp(command, "exit", 4) == 0)
			{
				free(command);
				return (2);
			}

		execute_command(args);
	}

	free(command);

	return (0);
}

/**
 * non_interactive_mode - The main interactive shell that
 *	prompts and accepts user input in a loop
 *
 * Return: (0)
 */
int non_interactive_mode(void)
{
	char *command = NULL;
	size_t len = 0;

	while (getline(&command, &len, stdin) != -1)
	{
		size_t command_len = my_strlen(command);

		if (command_len > 0 && command[command_len - 1] == '\n')
		{
			command[command_len - 1] = '\0';
		}

		execute_non_interactive(command);
	}

	free(command);
	return (0);
}

