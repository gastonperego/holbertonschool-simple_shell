#include "shell.h"
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
*@cmd: Array of arguments
*/
void shell_exit(char **cmd)
{
	int sta_tus = 0;

	if (cmd[1] == NULL)
	{
		free_dp(cmd);
		exit(0);

	sta_tus = atoi(cmd[1]);
	free_dp(cmd);

	if (sta_tus == 0)
		exit(2);
	else
		exit(sta_tus);
	}
}
