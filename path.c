#include "shell.h"

/**
 * path - Execute a command based on its path or name.
 * @cmd: The command to execute.
 *
 * Return: 0 on success, 1 on failure.
 */
int path(char *cmd)
{
	char *argv[MAX_CMD_LENGTH / 2];
	int i = 0;
	char *token;
	int result;
	char *full_path;

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (cmd[0] == '/')
	{
		result = execute_command(cmd, argv);
		return (result);
	}

	full_path = get_command_path(argv[0]);
	if (!full_path)
	{
		fprintf(stderr, "Command not found: %s\n", argv[0]);
		return (1);
	}

	result = execute_command(full_path, argv);
	free(full_path);
	return (result);
}
