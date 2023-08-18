#include "shell.h"
/**
 *main - Program that is simple UNIX command interpreter
 *Return: Nothing
 */
int main(void)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	int cicles = 0;

	while (1)
	{
		cicles++, prompt();
		chars_readed = getline(&buffer, &buf_size, stdin);
		if (chars_readed == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			command = tokening(buffer, " \t\n");
			free(buffer);
			if (strcmp(command[0], "exit") == 0)
				shell_exit(command);
			else if (strcmp(command[0], "cd") == 0)
			{
				if (command[1] != NULL)
				{
					if (change_dir(command[1]) == 0)
						printf("Failed to change directory to %s\n", command[1]);
					else
						printf("Changed directory to %s\n", command[1]);
				}
				else
					printf("Usage: cd <directory>\n");
				free_dp(command);
			}
			else
				create_child(command, cicles);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
*prompt - print the prompt
*/
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}

/**
*handle - handle signals
*@signals: status signals
*/
void handle(int signals)
{
	(void)signals;
	printf("\n$ ");
}

/**
*_EOF - End of file
*@buffer: Imput string
*/
void _EOF(char *buffer)
{
	if (buffer)
		free(buffer);
	if (isatty(STDIN_FILENO))
		printf("\n");
	exit(EXIT_SUCCESS);
}

/**
*shell_exit - Exit the shell
*@command: Array of arguments
*/
void shell_exit(char **cmd)
{
    int sta_tus = 0;

    if (cmd[1] == NULL)
    {
        free_dp(cmd);
        exit(2);
    }

    sta_tus = atoi(cmd[1]);
    free_dp(cmd);
    exit(sta_tus);
}

