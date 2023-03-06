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
