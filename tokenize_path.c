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

/**
 * tok_num - calcs num of toks in str
 * @str: string to tokenize
 * @delims: delims to tokenize based on
 * Return: num of tokens in overall str
 */
int tok_num(char *str, char *delims)
{
	int tokTotal = 0, i, lineLen = 0;

	lineLen = _strlen(str);
	for (i = 0; i < lineLen; i++)
	{
		if (str[i] && str[i] != delims[0] && str[i] != delims[1])
		{
			tokTotal++;
			i += substrLen(str + i, delims);
		}
	}
	return (tokTotal);
}

/**
 * substrLen - computes length of substr / token
 * @str: string in question
 * @delims: delims to tok based on
 * Return: length of substr
 */
int substrLen(char *str, char *delims)
{
	int i = 0;

	while (str[i] && str[i] != delims[0] && str[i] != delims[1])
	{
		i++;
	}
	return (i);
}
