#include "shell.h"

/**
 * tokenize_path_the_sequel - tokenize user's PATH variable
 * @line: supplied PATH variable content
 * @delims: delimiter string
 * @tokens: array of tokens
 * Return: void
 */
void tokenize_path_the_sequel(char *line, char *delims, char **tokens)
{
	char *saveptr;
	char *path_token = tokstr(line, delims, &saveptr);
	int i = 0;

	while (path_token != NULL)
	{
		tokens[i] = path_token;
		i++;
		path_token = tokstr(NULL, delims, &saveptr);
	}
	tokens[i] = NULL;
}
