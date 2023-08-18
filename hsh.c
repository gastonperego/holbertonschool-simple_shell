#include "shell.h"
/**
 *main - Program that is simple UNIX command interpreter
 *Return: Nothing
 */

int main(void)
{
	char *buffer = NULL, **cmd = NULL;
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
			cmd = tokening(buffer, " \n\t");
			free(buffer);
			if (cmd != NULL)
			{
				if (strcmp(cmd[0], "exit") == 0)
					shell_exit(cmd);
				else
				{
					create_child(cmd, cicles); } } }
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

