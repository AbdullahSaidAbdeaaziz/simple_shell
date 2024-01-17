#include "shell.h"

/**
 * main - Entry point for simple shell
 * @void: no args
 * Returns: 0 on success
*/

int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGUMENTS];

	while (1)
	{
		print_prompt();
		if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			perror("shell");
			exit(EXIT_FAILURE);
		}
		handle_input(input, args);
	}

	return (0);
}
