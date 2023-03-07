#include "shell.h"

/**
 * execute_command - executes the supplied command if possible
 * @args: command argument array
 * @paths: paths to search for command in
 * Return: void
 */
void execute_command(char **args, char **paths)
{
	pid_t pid, wpid;
	int status, i = 0;
	char *command_path = NULL;

	pid = fork();
    /*child proc PID*/
	if (pid == 0)
	{
		if (access(args[0], X_OK) == 0)
			if (execv(args[0], args) == -1)
				ext_msg(EXIT_FAILURE, "Error executing command\n");
		i = 0;
		while (paths[i] != NULL)
		{
			command_path = malloc(_strlen(paths[i]) + _strlen(args[0]) + 2);
			sprintf(command_path, "%s/%s", paths[i], args[0]);
			if (access(command_path, X_OK) == 0)
			{
				args[0] = command_path;
				if (execv(args[0], args) == -1)
					ext_msg(EXIT_FAILURE, "Error executing command\n");
			}
			free(command_path);
			i++;
		}
		ext_msg(EXIT_FAILURE, "Command not found\n");
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
	(void) wpid;
}
