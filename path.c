#include "shell.h"

/**
 * path - Execute a command based on its path or name.
 * @cmd: The command to execute.
 * Return: 0 on success, 1 on failure.
 */
int path(char *cmd)
{
	char *full_path;
	char *argv[MAX_CMD_LENGTH / 2];
	int i = 0;
	int result;
	char *token;

	if (strcmp(cmd, "/bin/ls") == 0)
	{
		char *ls_argv[] = {"/bin/ls", NULL};

		return (execute_command("/bin/ls", ls_argv));
	}

	token = strtok(cmd, " \t\n");
	if (token == NULL)
	{
		return (100);
	}
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	full_path = get_command_path(argv[0]);

	if (!full_path)
	{
		fprintf(stderr, "Command not found: %s\n", argv[0]);
		return (1);
	}

	result = execute_command(full_path, argv);
	return (result);
}
