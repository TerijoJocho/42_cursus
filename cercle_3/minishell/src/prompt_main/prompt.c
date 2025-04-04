/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:38:05 by daavril           #+#    #+#             */
/*   Updated: 2025/04/05 01:11:52 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		g_signal;

int	clone_envp(t_clone **cl, char **envp)
{
	t_clone	*node;
	t_clone	*last;
	int		i;

	last = NULL;
	i = -1;
	if (!envp || !envp[0])
		return (1);
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
	return (0);
}

void	free_all(t_master *master)
{
	clean_values(&master->token_list);
	token_clear(&master->token_list);
	cmd_clear(&master->cmd_list);
	if (master->env != NULL)
	{
		free_tab(master->env);
		master->env = NULL;
	}
}

int	init_master(t_master *master, char **envp)
{
	master->flag = 0;
	master->env_clone = NULL;
	master->export_list = NULL;
	master->token_list = NULL;
	master->cmd_list = NULL;
	master->env = NULL;
	clone_envp(&master->env_clone, envp);
	clone_envp(&master->export_list, envp);
	if (!master->env_clone)
		return (free(master), 1);
	set_signal();
	return (0);
}

void	go_minishell(t_master *master)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		master->token_list = NULL;
		if (!input)
			break ;
		else if (input[0] == '\0' || input[0] == ' ')
			add_history(input);
		else if (*input)
		{
			add_history(input);
			if (lexer(input, &master->token_list) == 1)
				printf("Error lexer\n");
			else if (syntax_check(&master->token_list) == 1)
				printf("Command line syntax error\n");
			else if (parser(master) == 1)
				printf("Error parsing\n");
			else if (executor(master) == 1)
				printf("Error exec\n");
		}
		free(input);
		free_all(master);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_master	*master;

	(void)argc;
	(void)argv;
	master = malloc(sizeof(t_master));
	if (!master)
	{
		printf("Error\n");
		return (1);
	}
	init_master(master, envp);
	go_minishell(master);
	clean_env(&master->env_clone);
	clean_env(&master->export_list);
	if (master->env_clone)
		printf("caca\n");
	free(master);
	master = NULL;
	printf("exit\n");
	return (0);
}
