#include "prompt.h"
#include "../../includes/minishell.h"

// cc lexer.c -I../libft -L../libft -lft -lreadline
//gcc -Wall -Wextra -Werror -I. -I../../libft *.c -L../../libft -lft -lreadline -o minishell


int main(void)
{
    char    *input;
    t_token *token_list;

    while (1)
    {
        input = readline("minishell$ ");
        if (!input)
            break ;
        if (*input)
            add_history(input);
        token_list = NULL;
        if (lexer(input, &token_list) == 1)
            printf("Error\n");
        // else if (parsing(&token_list) == 1)
        //     printf("Error\n");
        // else
        //     break ;
        /*TEST------------------------------------*/
        t_token *current = token_list;
		while (current)
		{
			// printf("Current value: %p, Prev value: %p\n", current, current->prev);
			printf("Type: %d, Real: %d, Value: %s, Is Expand:%d\n", current->type, current->real, current->value, current->is_expand);
			current = current->next;
		}
        /*----------------------------------------*/
        token_clear(&token_list);
        free(input);
    }
    printf("exit\n");
    return (0);
}