#include "shell.h"

/**
 * execute_command - executes the supplied command if possible
 * @args: command argument array
 * @paths: paths to search for command in
 * Return: void
 */
int execute_command(char **args, char **paths)
{
	int i = 0, exret = 0;
	char *command_path = NULL;

	if (access(args[0], X_OK) == 0)
	{
		exret = forktime(args);
		return (exret);
	}
	for (; paths[i] != NULL; i++)
	{
		command_path = malloc(_strlen(paths[i]) + _strlen(args[0]) + 2);
		sprintf(command_path, "%s/%s", paths[i], args[0]);
		if (access(command_path, X_OK) == 0)
		{
			args[0] = command_path;
			exret = forktime(args);
		}
		free(command_path);
	}
	return (exret);
}

int forktime(char **args)
{
	pid_t pid, wpid;
	int status = 0;

	pid = fork();
    /*child proc PID*/
	if (pid == 0)
	{
		if (execv(args[0], args) == -1)
			ext_msg(EXIT_FAILURE, "Error executing command\n");
	}

    /* handle possible fork error */
	else if (pid < 0)
		ext_msg(EXIT_FAILURE, "Error forking\n");

	/* otherwise is/are parent */
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
	(void) wpid;
}
