#include "shell.h"

/**
 * path - Execute a command based on its path or name.
 * @cmd: The command to execute.
 * Return: 0 on success, 1 on failure.
 */
int path(char *cmd)
{
	if (strcmp(cmd, "/bin/ls") == 0)
	{
		char *argv[] = {"/bin/ls", NULL};

		return (execute_command("/bin/ls", argv));
	}

	char *argv[MAX_CMD_LENGTH / 2];
	int i = 0;

	char *token = strtok(cmd, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	char *full_path = get_command_path(argv[0]);

	if (!full_path)
	{
		fprintf(stderr, "Command not found: %s\n", argv[0]);
		return (1);
	}

	int result = execute_command(full_path, argv);

	free(full_path);
	return (result);
}
