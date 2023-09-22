#include "shell.h"
/**
 * env - function that prints the current environment
 * Return: nothing
 */
void env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		print("%s\n", environ[i]);
	}
}
