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

	input_copy = strdup(input);
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
	if (count == 1)
	{
		return (NULL);
	}
	av = malloc(sizeof(char *) * count);
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
 *@cmd: array of arguments
 *@cicles: counter
 */
void create_child(char **cmd, int cicles)
{
	int sta, i = 0, exit_status = 2;
	struct stat st;
	char **path = NULL;
	(void)cicles;

	while (cmd[i] != NULL)
	{
		i++;
	}

	if (strcmp(cmd[0], "env") == 0 && i == 1)
	{
		print_env();
		free_dp(cmd);
		return;
	}
	sta = stat(cmd[0], &st);

	if (sta == 0)
	{
		forker(cmd, &exit_status);
		printf("exit_status = %d\n", exit_status);
	}
	else
	{
		path = get_path();
		forker2(cmd, path, cicles);
		free_dp(path);
	}
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
 *@cmd: Array of arguments
 *@exit_status: Exit status value
 */
void forker(char **cmd, int *exit_status)
{
	int status = 0;
	pid_t pid = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_dp(cmd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(cmd[0], cmd, environ) < 0)
		{
			perror("Error executing cmd");
			free_dp(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			*exit_status = WEXITSTATUS(status);
			free_dp(cmd);
			exit(*exit_status);
		}
	}
}

/**
 *forker2 - Second step to fork
 *@cmd: Array of arguments
 *@path: The path
 *@cicles: counter
 */
void forker2(char **cmd, char **path, int cicles)
{
	char *full_path = NULL;
	struct stat st;
	pid_t pid;
	int i = 0, status = 0;

	while (path[i])
	{
		full_path = malloc(sizeof(char) * (strlen(path[i]) + strlen(cmd[0]) + 2));
		if (full_path == NULL)
		{
			perror("Error de asignación de memoria"), free_dp(path);
			free_exit(cmd);
		} strcpy(full_path, path[i]), strcat(full_path, "/");
		strcat(full_path, cmd[0]);
		if (stat(full_path, &st) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(full_path, cmd, environ) < 0)
					perror(cmd[0]), free_dp(path), free_exit(cmd);
			} else if (pid > 0)
			{
				waitpid(pid, &status, 0);
				if (WIFEXITED(status))
				{
					status = WEXITSTATUS(status);
					if (status != 0)
						fprintf(stderr, "Exited with status: %d\n", status);
				}
			} else
				printf("errror\n");
			break;
		} free(full_path), i++;
	}
	if (path[i] != NULL)
		free(full_path);
	else
		msgerror(cicles, cmd);
	free_dp(cmd);
}
