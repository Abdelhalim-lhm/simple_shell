#include "shell.h"
/**
 * path - Execute a command based on its path or name.
 * @cmd: The command to execute.
 * Return: 0 on success, status on failure.
 */
int path(char *cmd)
{
	char *argv[MAX_CMD_LENGTH / 2], *token, *full_path;
	int result, cmd_len, i = 0;

	token = strtok(cmd, " \t\n");
	if (token == NULL)
	{
		free(cmd);
		return (100);
	}
	while (*cmd == ' ')
	{
		cmd++;
	}
	cmd_len = _strlen(cmd);
	while (cmd_len > 0 && cmd[cmd_len - 1] == ' ')
	{
		cmd[cmd_len - 1] = '\0';
		cmd_len--;
	}
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
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
		print("hsh:%s: command not found\n", argv[0]);
		return (127);
	}
	result = execute_command(full_path, argv);
	free(full_path);
	return (result);
}
