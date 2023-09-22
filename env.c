#include "shell.h"
/**
 * env - function that prints the current environment
 * Return: nothing
 */
void env(void)
{
	char **env = environ;

	for (; *env != NULL; env++)
	{
		print("%s\n", *env);
	}
}
