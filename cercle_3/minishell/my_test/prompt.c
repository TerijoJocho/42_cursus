#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void)
{
    char    *result;

    while (1)
    {
        result = readline("minishell$");
        if (!result)
        {
            printf("exit\n");
            break;
        }
        if (*result)
            add_history(result);
        printf("Commmand :%s\n", result);
        free(result);
    }
    return (0);
}