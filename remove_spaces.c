#include "shell.h"

/**
 * remove_spaces - this removes space in buffer
 * @state: a state of string
 */
void remove_spaces(char *state)
{
	int len, i, j = 0;

	len = strlen(state);
	for (i = 0; i < len; i++)
	{
		if (state[i] != ' ')
			state[j++] = state[i];
	}
	state[j] = '\0';
}
