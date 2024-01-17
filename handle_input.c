#include "shell.h"

/**
 * check_args - check arguments
 * @num_args: number of arguments
 * @args: list of arguments
 * Return: None
*/

void check_args(int num_args, char **args)
{
	int i, redirect, fd;

	if (num_args > 0)
	{
		redirect = 0;
		for (i = 0; i < num_args; ++i)
		{
			if (strcmp(args[i], ">") == 0)
			{
				redirect = 1;
				args[i] = NULL;

				fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
				if (fd == -1)
				{
					perror("shell");
					exit(EXIT_FAILURE);
				}

				dup2(fd, STDOUT_FILENO);
				close(fd);
			}
		}

		if (!redirect)
		{
			execute_command(args);
		}

		dup2(1, STDOUT_FILENO);
	}
}

/**
 * handle_input - filter input for command in shell
 * @input: input string
 * @args: command arguments that will be passed to
 * shell command
 * Return: None
*/

void handle_input(char *input, char **args)
{
	int num_args;

	input[strcspn(input, "\n")] = '\0';

	if (strcmp(input, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	num_args = parse_input(input, args);
	check_args(num_args, args);
}
