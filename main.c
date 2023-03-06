#include "shell.h"

/**
 * main - Entry point for ghost
 * @argc: arg count
 * @argv: array of input arg strings
 * Return: Always 0. Exit status differs.
 */
int main(int argc, char *argv[])
{
	char *comsave = NULL, *prompt = NULL, *path = NULL, *token = NULL;
	char buffer[BUFFER_SIZE], *args[20], *paths[20], *pname = argv[0];
	ssize_t nread;
	int i = 0;

	prompt = "$ ";
	path = getenv("PATH");
	tokenize_path(path, paths);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		nread = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (nread == -1)
			ext_msg(EXIT_FAILURE, "Error reading input\n");
		else if (nread == 0)
			ext_msg(EXIT_SUCCESS, "\nGoodbye!\n");
		buffer[nread] = '\0';
		token = tokstr(buffer, TOKEN_DELIMITERS, &comsave);
		i = 0;
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = tokstr(NULL, TOKEN_DELIMITERS, &comsave);
		}
		args[i] = NULL;
		if (_strcmp(args[0], "exit") == 0)
			ext_msg(EXIT_SUCCESS, "Goodbye!\n");
		else if (_strcmp(args[0], "env") == 0)
			print_environment();
		else
			execute_command(args, paths);
	}
	return (0);
	(void) argc;
	(void) pname;
}
