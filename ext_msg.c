#include "shell.h"

/**
 * ext_msg - exits with a given status and message
 * @status: program exit status
 * @msg: message to print to STDOUT on exit
 * Return: void
 */
void ext_msg(int status, char *msg)
{
	write(STDOUT_FILENO, msg, _strlen(msg));
	exit(status);
}
