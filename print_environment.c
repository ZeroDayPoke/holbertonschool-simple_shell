#include "shell.h"

/**
 * print_environment - prints user's env
 * Return: void
 */
void print_environment(void)
{
	int i = 0;
	char *env;

	while (environ[i] != NULL)
	{
		env = environ[i];
		write(STDOUT_FILENO, env, _strlen(env));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
