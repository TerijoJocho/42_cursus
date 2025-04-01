/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:38:05 by daavril           #+#    #+#             */
/*   Updated: 2025/04/01 12:41:50 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// cc lexer.c -I../libft -L../libft -lft -lreadline
// gcc -Wall -Wextra -Werror -I. -I../../libft prompt.c ../lexer/*.c -L../../libft -lft -lreadline -o minishell

int clone_envp(t_clone **cl, char **envp)
{
    t_clone	*node;
	t_clone	*last;
    int i;

	last = NULL;
	i = -1;
    if (!envp || !envp[0])
        return 1;
    while (envp[++i])
	{
        node = malloc(sizeof(t_clone));
		if (!node)
			return (clean_env(cl), 1);
		node->value = ft_strdup(envp[i]);
        if (!node->value)
			return (free(node), clean_env(cl), 1);
        node->next = NULL;
        node->prev = last;
        if (last)
            last->next = node;
        else
            *cl = node;
        last = node;
    }
    return 0;
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_master	*master;

	(void)argc; // verif si argc == 2
	(void)argv; // on s'en fiche
	master = malloc(sizeof(t_master));
	if (!master)
	{
		printf("Error\n");
		return (0);
	}
	master->env_clone = NULL;
	master->export_list = NULL;
	master->token_list = NULL;
	master->cmd_list = NULL;
	master->env = NULL;
	clone_envp(&master->env_clone, envp);
	clone_envp(&master->export_list, envp);
	if (!master->env_clone)
		return (free(master), 0);
	/*signal*/
	// setup_signal();
	/*------*/
	while (1)
	{
		input = readline("minishell$ ");
		master->token_list = NULL;
		if (!input)
			break ;
		// else if (input[0] == '\0')
		// 	add_history(input);
		else if (*input)
			add_history(input); //a gerer sino segfault
		if (lexer(input, &master->token_list) == 1)
			printf("Error lexer\n");
		else if (syntax_check(&master->token_list) == 1)
			printf("Command line syntax error\n");
		else if (parser(master) == 1)
			printf("Error parsing\n");
		else if (executor(master) == 1)
			printf("Error exec\n");
		// 	/*TEST------------------------------------*/
			// t_token	*current = master->token_list;
			// int	i = 1;
			// while (current)
			// {
			// 	printf("\n---Token %d---\n", i);
			// 	printf("Prog : %d, Dir: %d\nIs Expand: %d, single quote: %d, space flag : %d\nReal: %d\n", current->prog, current->dir, current->is_expand, current->quote_flag, current->space, current->real);
			// 	printf("value: %s\n", current->value);
			// 	printf("value_2: %s\n\n", current->value_2);
			// 	current = current->next;
			// 	i++;
			// }
		// 	/*----------------------------------------*/
		// }
		free(input);
		free_all(master);
	}
	clean_env(&master->env_clone);
	clean_env(&master->export_list);
	if (master->env_clone)
		printf("caca\n");
	free(master);
	master = NULL;
	printf("exit\n");
	return (0);
}
