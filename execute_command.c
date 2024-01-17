#include "shell.h"

/**
 * execute_command - Execute a command in a child process
 * @args: Array of command and its arguments
 *
 * This function creates a child process to execute the given command
 * with its arguments.
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("shell");
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("shell");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
