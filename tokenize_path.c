#include "shell.h"

/**
 * tokenize_path - tokenize user's PATH variable
 * @path: supplied PATH variable content
 * @paths: array to put paths tokens
 * Return: void
 */
void tokenize_path(char *path, char **paths)
{
	char *saveptr;
	char *path_token = tokstr(path, ":", &saveptr);
	int i = 0;

	while (path_token != NULL)
	{
		paths[i] = path_token;
		i++;
		path_token = tokstr(NULL, ":", &saveptr);
	}
	paths[i] = NULL;
}
