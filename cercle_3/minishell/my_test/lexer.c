#include "lexer.h"

void    add_token_list(t_list **token_list, int type, char *value)
{
    t_list  *new_node;
    t_token *new_token;

    if (!value)
        return ;
    new_token = malloc(sizeof(t_token));
    if (!new_token)
    {
        free(new_token);
        return ;
    }
    new_token->value = value;
    new_token->type = type;
    new_node = ft_lstnew(new_token);
    if (!new_node)
    {
        free(new_token->value);
        free(new_token);
        free(new_node);
        return ;
    }
    ft_lstadd_back(token_list, new_node);
}

/*premier cas, espace--------------*/
int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||c == '\r');
}

/*second cas, mot---------------*/
char    *extract_word(char *input)
{
    char *value;
    int i;

    i = 0;
    while (input[i] && !is_whitespace(input[i]))
        i++;
    value = malloc(sizeof(char) * (i + 1));
    if (!value)
        return (NULL);
    ft_strlcpy(value, input, i + 1);
    return(value);
}

int word_len(char *input)
{
    int i;

    i = 0;
    while (input[i] && !is_whitespace(input[i]))
        i++;
    return (i);
}

/*troisieme cas, special--------------*/
int     is_special_char(char c)
{
    return (c == '|' || c == '<' || c == '>' || c == '&');
}

int     is_sequence(char *input, char *sequence)
{
    int i;

    i = 0;
    while(sequence[i])
    {
        if (input[i] != sequence[i])
            return (0);
        i++;
    }
    return (1);
}      

char    *extract_special_char(char *input)
{
    char    *value;
   
    if (is_sequence(input, ">>"))
        return (ft_strdup(">>"));
    if (is_sequence(input, "<<"))
        return (ft_strdup("<<"));
    value = malloc(sizeof(char) * 2);
    if (!value)
        return (NULL);
    value[0] = input[0];
    value[1] = '\0';
    return (value);
}

int     special_char_len(char *input)
{
    if (is_sequence(input, "<<") || is_sequence(input, ">>"))
        return(2);
    return(1);
}

/*quatrieme cas, phrase----------*/
char    *extract_quoted_string(char *input, char quote)
{
    char    *value;
    int     i;

    i = 1;
    while (input[i] && input[i] != quote)
        i++;
    if (input[i] != quote)
        return (NULL); //erreur
    value = malloc(sizeof(char) * i);
    if (!value)
        return (NULL);
    ft_strlcpy(value, &input[1], i);
    return (value);
}

int     quoted_string_len(char *input)
{
    int i;

    i = 1;
    while (input[i] && input[i] != input[0])
        i++;
    if (input[i] == input[0])
        i++;
    return (i);
}

void    lexer(char *input, t_list **token_list)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (is_whitespace(input[i]))
            i++;
        else if (is_special_char(input[i]))
        {
            add_token_list(token_list, 2, extract_special_char(&input[i]));
            i += special_char_len(&input[i]);
        }
        else if (input[i] == '\'' || input[i] == '\"')
        {
            add_token_list(token_list, 3, extract_quoted_string(&input[i], input[i]));
            i += quoted_string_len(&input[i]);
        }
        else
        {
            add_token_list(token_list, 1, extract_word(&input[i]));
            i += word_len(&input[i]);
        }
    }
}

#include <readline/readline.h>
#include <readline/history.h>

//cc lexer.c -I../libft -L../libft -lft -lreadline 

int main(void)
{
    t_list *token_list;
    char *input;

    while (1)
    {
        input = readline("minishell> ");
        if (!input)
            break;
        if (*input)
            add_history(input);

        token_list = NULL;
        lexer(input, &token_list);

        t_list *current = token_list;
        while (current)
        {
            t_token *token = (t_token *)current->content;
            printf("Type: %d, Value: %s\n", token->type, token->value);
            current = current->next;
        }

        ft_lstclear(&token_list, free);
        free(input);
    }
    printf("Exiting minishell.\n");
    return 0;
}


// int main(int argc, char **argv)
// {
//     t_list  *token_list;
//     t_list  *current;
//     int i;

//     i = 1;
//     (void)argc;
//     token_list = NULL;
//     while (argv[i])
//     {
//         lexer(argv[i], &token_list);
//         i++;
//     }
//     current = token_list;
//     while (current)
//     {
//         t_token *token = (t_token *)current->content;
//         printf("Type: %d, Value: %s\n", token->type, token->value);
//         current = current->next;
//     }
//     ft_lstclear(&token_list, free);
//     return (0);
// }