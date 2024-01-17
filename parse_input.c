#include "shell.h"

/**
 * parse_input - parse user input into an array
 * of arguments
 * @input: user input
 * @args: array of arguments that will store in it
 * Return: number of arguments
*/

int parse_input(char *input, char **args)
{
	int i = 0;
	char *token;

	token = strtok(input, " \t\n\r\a");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n\r\a");
	}
	args[i] = NULL;

	return (i);
}
