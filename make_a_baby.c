#include "shell.h"

/**
 * make_a_baby - creates a child process
 * @comp_path: path to executable
 * @tokens: array of tokens
 * Return: status of child process
 */

int make_a_baby(char *comp_path, char **tokens)
{
	pid_t pid, CoP;
	int status = 0;

	pid = fork();
	if (pid == 0)
	{
		if (execve(comp_path, tokens, NULL) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			CoP = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	(void) CoP;
	return (status);
}
