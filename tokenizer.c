#include "shell.h"
/**
*tokening - makes tokens from the input string
*@input: input string from getline
*@delim: delimiter to separate the tokens
*Return: array of tokens
*/
char **tokening(char *input, char *delim)
{
	char *input_copy, *token, **av;
	int count = 0, i = 0;

	input_copy = strdup(input); /*FREE INPUT COPY*/
	if (input_copy == NULL)
		exit(-1);
	token = strtok(input_copy, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(input_copy);
	count++;

	av = malloc(sizeof(char *) * count); /*FREE AV*/
	if (av == NULL)
		exit(-1);
	token = strtok(input, delim);
	while (token != NULL)
	{
		av[i] = strdup(token);
		if (av[i] == NULL)
			exit(-1);
		token = strtok(NULL, delim);
		i++;
	}
	av[i] = NULL;
	return (av);
}

/**
 *create_child - first step to create child process
 *@command: array of arguments
 *@cicles: counter
 */
void create_child(char **command, int cicles)
{
	int sta, i = 0;
	struct stat st;
	char **path = NULL;
	(void)cicles;

	path = get_path();
	while (command[i] != NULL)
		i++;

	if (strcmp(command[0], "env") == 0 && i == 1)
	{
		print_env();
		free_dp(command);
		free_dp(path);
		return;
	}
	sta = stat(command[0], &st);

	if (sta == 0)
		forker(command, path);
	else
		forker2(command, path);
}

/**
 *get_path - Function that get the path
 *Return: Path
 */
char **get_path()
{
	char *env_copy, *pathkey, *pathvalue, **path;
	int i = 0;

	while (environ[i])
	{
		env_copy = strdup(environ[i]);
		if (env_copy == NULL)
			return (NULL);
		pathkey = strtok(env_copy, "=");
		if (strcmp(pathkey, "PATH") == 0)
		{
			pathvalue = strtok(NULL, " \n\t");
			path = tokening(pathvalue, ":");
		}
		i++;
		free(env_copy);
	}
	return (path);
}

/**
 *forker - First step to fork
 *@command: Array of arguments
 *@path: The path
 */
void forker(char **command, char **path)
{
	int status = 0, wait_error = 0;
	pid_t pid = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_dp(command);
		free_dp(path);
		exit(EXIT_FAILURE); }
	else if (pid == 0)
	{
		execve(command[0], command, NULL);
		perror("Error executing command");
		free_dp(command);
		free_dp(path);
		exit(EXIT_FAILURE); }
	else
	{
	wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			perror("Error waiting for child process");
			free_dp(command);
			free_dp(path);
			exit(EXIT_FAILURE); }
			free_dp(command);
			free_dp(path);
		}
}

/**
 *forker2 - Second step to fork
 *@command: Array of arguments
 *@path: The path
 */
void forker2(char **command, char **path)
{
	char *full_path = NULL;
	struct stat st;
	pid_t pid;
	int i = 0, status = 0;

	while (path[i])
	{
		char *temp_path = strdup(path[i]);

		if (temp_path == NULL)
		{
			perror("Memory allocation error");
			free_dp(path), free_exit(command);
		}
		full_path = strcat(temp_path, "/");
		full_path = strcat(full_path, command[0]);

		if (stat(full_path, &st) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(full_path, command, NULL) < 0)
				{
					perror(command[0]);
					free(temp_path);
					free_dp(path);
					free_exit(command);
				}
			}
			else
				waitpid(pid, &status, 0);
			free(temp_path);
			free_dp(path);
			free_dp(command);
			return;
		}
		free(temp_path), i++;
	}
	free_dp(path);
}

