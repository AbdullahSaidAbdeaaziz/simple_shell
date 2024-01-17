#include "shell.h"

/**
 * _print - write to console output
 * @msg: the message to print
 * Return: None
*/

void _print(const char *msg)
{
	write(STDOUT_FILENO, msg, strlen(msg));
}
