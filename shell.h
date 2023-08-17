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

int main();
void prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);
void print_env();
char **_getPATH(char **env);
void msgerror(int cicles, char **command);
char **get_path();
void create_child(char **command, int cicles);
void free_dp(char **command);
void free_exit(char **command);
char **tokening(char *input, char *delim);
int change_dir(const char *path);
void forker(char **command, char **path);
void forker2(char **command, char **path);

#endif
