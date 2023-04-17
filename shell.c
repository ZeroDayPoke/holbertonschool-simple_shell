#include "shell.h"

extern char **environ;

/**
 * main - Entry point for ghost
 * @argc: arg count
 * @argv: array of input arg strings
 * Return: Always 0. Exit status differs.
 */
int main(int argc, char *argv[])
{
	char *comsave = NULL, *prompt = NULL, *path = NULL, *token = NULL;
	char *line = NULL, *args[40], *paths[40], *pname = argv[0], *env = NULL;
	size_t nread = 0;
	int i = 0, j = 0;
	char *comp_path = NULL;
	struct stat x;

	prompt = "$ ";
	while (1)
	{
		path = strdup(getenv("PATH"));
		tokenize_path(path, paths);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		if (getline(&line, &nread, stdin) < 0)
		{
			free(line);
			free(path);
			exit(EXIT_SUCCESS);
		}
		cleanstr(line);
		if (line[0] == '\0')
		{
			free(path);
			continue;
		}
		token = tokstr(line, DELIMS, &comsave);
		if (!token[0])
		{
			free(path);
			continue;
		}
		 i = 0;
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = tokstr(NULL, DELIMS, &comsave);
		}
		args[i] = NULL;
		if (_strcmp(args[0], "exit") == 0)
		{
			free(line);
			free(path);
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(args[0], "env") == 0)
		{
			for (j = 0; environ[j]; j++)
			{
				env = environ[j];
				write(STDOUT_FILENO, env, _strlen(env));
				write(STDOUT_FILENO, "\n", 1);
			}
			free(path);
			continue;
		}
		if (access(args[0], X_OK) == 0)
			make_a_baby(args[0], args);
		else
		{
			i = 0;
			while (paths[i] != NULL)
			{
				comp_path = malloc(_strlen(args[0]) + _strlen(paths[i]) + 2);
				_strcpy(comp_path, paths[i]);
				_strcat(comp_path, "/");
				_strcat(comp_path, args[0]);
				if (stat(comp_path, &x) == 0)
				{
					make_a_baby(comp_path, args);
					free(comp_path);
					break;
				}
				free(comp_path);
				i++;
			}
		}
		free(path);
	}
	(void) argc;
	(void) pname;
	return (0);
}
