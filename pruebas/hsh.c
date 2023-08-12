#include "main.h"
int main()
{
    char *input = NULL, **argv = NULL;
    size_t n = 0;
    ssize_t get;
    int i = 0;

    printf("$ ");
    get = getline(&input, &n, stdin);
    if (get == -1 || strcmp(input, "exit") == 0)
    {
        free(input);
        printf("\n");
        return (-1);
    }
    argv = tokenizer(input);
    while (argv[i] != NULL)
    {
        free(argv[i]);
        i++;
    }
    free(argv);
    free(input);
    
    return(0);
}