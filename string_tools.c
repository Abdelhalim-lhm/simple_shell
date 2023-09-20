#include "shell.h"
/**
 * _strlen - function that gives the lenght of a string
 * @s : the character
 * Return: lenght of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
	{
		i++;
	}
return (i);
}
/**
 * _strcmp - function that compare 2 strings
 * @s1 : first string
 * @s2 : second string
 * Return: 0 on succes
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;

	}
	return (0);
}
