#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#define MAX_CMD_LENGTH 100
#define MAX_PATH_LENGTH 256
extern char **environ;
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *get_linecmd(void);
int path(char *);
char *get_command_path(char *cmd);
int execute_command(char *full_path, char *argv[]);
void print(const char *format, ...);
void env(void);
#endif
