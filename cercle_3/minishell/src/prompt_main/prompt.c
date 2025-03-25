/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:38:05 by daavril           #+#    #+#             */
/*   Updated: 2025/03/25 16:00:40 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// cc lexer.c -I../libft -L../libft -lft -lreadline
// gcc -Wall -Wextra -Werror -I. -I../../libft prompt.c ../lexer/*.c -L../../libft -lft -lreadline -o minishell

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
			clean_env(env_clone);
			return ;
		}
		new_node->value = ft_strdup(envp[i]);
		if (!new_node->value)  // Vérification du strdup
		{
			free(new_node);
			clean_env(env_clone);
			printf("Malloc error\n");
			return ;
		}
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
	master->export_list = NULL;
	master->token_list = NULL;
	master->cmd_list = NULL;
	clone_envp(&master->env_clone, envp);
	clone_envp(&master->export_list, envp);
	if (!master->env_clone)  // Si clone_envp a échoué
	{
		free(master);
		return (0);
	}
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
		// 	add_history(input); // CA LA ADD APRES
		else if (*input) // rajouter verif si que des espaces || GERER CA APRES LOL
			add_history(input);
		if (lexer(input, &master->token_list) == 1)
			printf("Error lexer\n");
		else if (syntax_check(&master->token_list) == 1)
			printf("Command line syntax error\n");
		else if (parser(master) == 1)
			printf("Error parsing\n");
		else if (executor(master) == 1)
			printf("Error exec\n");
		// else
		// {
		// 	/*TEST------------------------------------*/
		// 	t_token	*current = master->token_list;
		// 	int	i = 1;
		// 	while (current)
		// 	{
		// 		printf("\n---Token %d---\n", i);
		// 		printf("Prog : %d, Dir: %d\nIs Expand: %d, single quote: %d, space flag : %d\nReal: %d\n", current->prog, current->dir, current->is_expand, current->quote_flag, current->space, current->real);
		// 		printf("value: %s\n", current->value);
		// 		printf("value_2: %s\n\n", current->value_2);
		// 		current = current->next;
		// 		i++;
		// 	}
		// 	/*----------------------------------------*/
		// }
		free(input);
		free_all(master);
	}
	clean_env(&master->env_clone);
	free(master);
	master = NULL;
	printf("exit\n");
	return (0);
}
