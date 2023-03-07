#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

extern char **environ;

void execute_command(char **args, char **paths);
void print_environment(void);
void tokenize_path(char *path, char **paths);
char *tokstr(char *str, const char *delim, char **saveptr);
int tok_num(char *str, char *delims);
int substrLen(char *str, char *delims);

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);

unsigned int _strspn(char *s, const char *accept);
char *_strchr(const char *s, char c);
char *_strpbrk(char *s, const char *accept);
int cleanstr(char *line);

void ext_msg(int status, char *msg);

#endif
