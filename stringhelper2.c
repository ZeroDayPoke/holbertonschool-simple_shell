#include "shell.h"
/**
 * *_strchr - points to first instance of c in s
 * @s: input string
 * @c: char to be located
 * Return: point to first instance or NULL if none
 */
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *) s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *) s);
	}
	return (NULL);
}
/**
 * cleanstr - removes newline chars from user input
 * @line: user input line
 * Return: always 0
 */
int cleanstr(char *line)
{
	int i = 0;

	if (line == NULL || (line[0] == '\n' && line[1] == '\0'))
		    return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
		}
		i++;
	}
	return (0);
}
/**
 * _strspn - calculates byte overlap
 * @s: input string
 * @accept: string w/ bytes to be accepted
 * Return: num of target byte matches
 */
unsigned int _strspn(char *s, const char *accept)
{
	unsigned int bCount = 0;
	int i = 0, j = 0;

	while (accept[i])
	{
		j = 0;
		while ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
		{
			if (s[j] == accept[i])
			{
				bCount++;
			}
			j++;
		}
		i++;
	}
	return (bCount);
}

/**
 * path_sweeper - free's the path and exit failure
 * @path: path to be freed
 * Return: always 0
 */

void path_sweeper(char *path)
{
	free(path);
	exit(EXIT_FAILURE);
}
