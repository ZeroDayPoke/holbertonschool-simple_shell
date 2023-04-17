#include "shell.h"

/**
 * path_finder - finds the path of the command
 * @tokens: the command to find
 *
 * Return: 0 if success, 127 if not
*/

int path_finder(char **tokens)
{
	char *path = NULL;
	char *paths[20];
	int i = 0;
	char *comp_path = NULL;
	struct stat x;

	path = getenv("PATH");
	tokenize_path(path, paths);
	while (paths[i] != NULL)
	{
		comp_path = malloc(_strlen(tokens[0]) + _strlen(paths[i]) + 2);
		_strcpy(comp_path, paths[i]);
		_strcat(comp_path, "/");
		_strcat(comp_path, tokens[0]);
		if (stat(comp_path, &x) == 0)
		{
			make_a_baby(comp_path, tokens);
			return (0);
		}
		free(comp_path);
		i++;
	}
	return (127);
}
