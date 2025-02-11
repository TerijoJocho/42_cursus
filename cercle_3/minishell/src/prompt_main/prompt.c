/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:38:05 by daavril           #+#    #+#             */
/*   Updated: 2025/02/11 15:41:20 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "../../includes/minishell.h"

// cc lexer.c -I../libft -L../libft -lft -lreadline
//gcc -Wall -Wextra -Werror -I. -I../../libft prompt.c ../lexer/*.c -L../../libft -lft -lreadline -o minishell

void	clone_envp(t_clone  **env_clone, char **envp)
{
	int i;
	t_clone *new_node;
	t_clone *last;

	i = -1;
	last = NULL;
	if (!envp || !envp[0])
		return ;
	while (envp[++i])
	{
		new_node = malloc(sizeof(t_clone));
		if (!new_node)
		{
			printf("Malloc error\n");
			return ;
		}
		new_node->value = ft_strdup(envp[i]);
		new_node->next = NULL;
		new_node->prev = last;
		if (last)
			last->next = new_node;
		else
			*env_clone = new_node;
		last = new_node;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_master	*master;

	(void)argc;
	(void)argv;
	master = malloc(sizeof(t_master));
	if (!master)
	{
		printf("Error\n");
		return (0);
	}
	master->env_clone = NULL;
	master->token_list = NULL;
	clone_envp(&master->env_clone, envp);
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (*input)
			add_history(input);
		master->token_list = NULL;
		if (lexer(input, &master->token_list) == 1)
			printf("Error lexer\n");
		// else if (parsing(&master->token_list) == 1)
		//     printf("Error parsing\n");
		// else
		//     break ;
		/*TEST------------------------------------*/
		t_token	*current = master->token_list;
		while (current)
		{
			// printf("Current value: %p, Prev value: %p\n", current, current->prev);
			printf("Real: %d, Value: %s, Is Expand: %d, single quote: %d, space flag : %d\n", current->real, current->value, current->is_expand, current->quote_flag, current->space);
			current = current->next;
		}
		// t_clone *current = master->env_clone;
		// int i = 0;
		// while (current)
		// {
		//     printf("actuel : %d, contenu : %s\n", i, current->value);
		//     i++;
		//     current = current->next;
		// }
		/*----------------------------------------*/
		token_clear(&master->token_list);
		free(input);
	}
	printf("exit\n");
	return (0);
}
