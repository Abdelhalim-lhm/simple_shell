#include "shell.h"

/**
 * execute_command - Execute a command with given arguments.
 * @full_path: The full path to the executable.
 * @argv: An array of command arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int execute_command(char *full_path, char *argv[])
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(full_path, argv, environ) == -1)
		{
			perror("execve");
			free(full_path);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (0);
}
