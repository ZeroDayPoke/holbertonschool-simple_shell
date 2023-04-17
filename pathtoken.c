#include "shell.h"

/**
 * tokstr - tokenizes string input based on delims
 * @str: string to tokenize
 * @delim: delim(s) to make tokens based on
 * @saveptr: save point in the string
 * Return: token
 */
char *tokstr(char *str, const char *delim, char **saveptr)
{
	char *token;

	if (str == NULL)
	{
		str = *saveptr;
	}
	str += _strspn(str, delim);
	if (*str == '\0')
	{
		return (NULL);
	}
	token = str;
	str = _strpbrk(token, delim);
	if (str == NULL)
	{
		*saveptr = _strchr(token, '\0');
	}
	else
	{
		*str = '\0';
		*saveptr = str + 1;
	}
	return (token);
}

/**
 * *_strpbrk - locks first accepted byte
 * @s: input string
 * @accept: string w/ bytes to be accepted
 * Return: point to locked byte, or NULL if no match
 */
char *_strpbrk(char *s, const char *accept)
{
	int i = 0, j = 0, offset = 999;

	while (accept[i])
	{
		j = 0;
		while (s[j])
		{
			if (s[j] == accept[i])
			{
				if (j < offset)
				{
					offset = j;
				}
			}
			j++;
		}
		i++;
	}
	if (offset == 999)
		return (NULL);
	return (s + offset);
}
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
