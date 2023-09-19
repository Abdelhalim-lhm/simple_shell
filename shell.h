#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#define MAX_CMD_LENGTH 100
extern char **environ;
int exec_cmd(char *);
int path(char *);
char *get_command_path(char *cmd);
int execute_command(char *full_path, char *argv[]);
void print(const char *format, ...);
void env(void);
#endif
