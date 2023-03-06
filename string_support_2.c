#include "shell.h"

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
 * cleanstr - removes newline chars from user input
 * @line: user input line
 * Return: always 0
 */
int cleanstr(char *line)
{
	int i = 0;

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
