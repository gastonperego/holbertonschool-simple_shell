#include "shell.h"
/**
 *print_env - Prints enviroment
 */
void print_env(void)
{
	size_t i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
*free_dp - Frees command
*@command: Array of arguments
*/
void free_dp(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;
	while (command[i])
	{
	free(command[i]);
	i++;
	}
	free(command);
}

/**
*free_exit - Frees exit
*@command: Array of arguments
*/
void free_exit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}
	if (command[i] == NULL)
		free(command[i]);
	free(command);
	exit(EXIT_FAILURE);
}

/**
 *msgerror - Message error
 *@cicles: Counter of cicles
 *@command: Array of arguments
 */

void msgerror(int cicles, char **command)
{
	char c;

	c = cicles + '0';
	write(STDOUT_FILENO, command[0], strlen(command[0]));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 *change_dir - Function to change directories
 *@path: The path
 *Return: 1 on success
 */

int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 0;

	buf = getcwd(buf, size);
	printf("%s $ ", buf);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}

