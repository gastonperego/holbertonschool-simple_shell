#include "main.h"
char **tokenizer(char *input)
{
    char *input_copy, *token, *delim = " \n\t", **av;
    int count = 0, i = 0;

    input_copy = strdup(input);

    token = strtok(input_copy, delim);
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, delim);
    }
    free(input_copy);
    count++;

    av = malloc(sizeof(char *) * count);

    token = strtok(input, delim);
    while (token != NULL)
    {
        av[i] = strdup(token);
        token = strtok(NULL, delim);
        i++;
    }
    av[i] = NULL;
    return(av);    
}