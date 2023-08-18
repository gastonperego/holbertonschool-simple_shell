#ifndef _SHELL_H_
#define _SHELL_H_

/*
 * Allowed functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

extern char **environ;

/*
 * Prototypes
 */

int main(void);
void prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **cmd);
void print_env(void);
char **_getPATH(char **env);
void msgerror(int cicles, char **cmd);
char **get_path();
void create_child(char **cmd, int cicles);
void free_dp(char **cmd);
void free_exit(char **cmd);
char **tokening(char *input, char *delim);
void forker(char **cmd, int *exit_status);
void forker2(char **cmd, char **path, int cicles);

#endif
