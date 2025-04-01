/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:20:04 by daavril           #+#    #+#             */
/*   Updated: 2025/04/01 16:25:08 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_node(t_clone **head, t_clone *ec)
{
	if (!ec)
		return ;
	if (ec->prev)
		ec->prev->next = ec->next;
	else
		*head = ec->next;
	if (ec->next)
		ec->next->prev = ec->prev;
	free(ec->value);
	free(ec);
}

int	search_var(t_clone **list, char *arg)
{
	t_clone	*ec;
	t_clone	*next;
	int		flag;

	ec = *list;
	flag = 0;
	while (ec)
	{
		next = ec->next;
		if (ft_strncmp(ec->value, arg, ft_strlen(arg)) == 0
			&& (ec->value[ft_strlen(arg)] == '='
				|| ec->value[ft_strlen(arg)] == '\0'))
		{
			delete_node(list, ec);
			flag = 1;
		}
		ec = next;
	}
	return (flag);
}

void	ft_unset(t_master *master, t_cmd *cur_cmd)
{
	int	i;

	i = 1;
	if (!cur_cmd->args[i])
	{
		printf("unset : missing argument\n");
		return ;
	}
	while (cur_cmd->args[i])
	{
		if (search_var(&master->export_list, cur_cmd->args[i]) == 0)
			printf("unset : no such variable: %s\n", cur_cmd->args[i]);
		if (search_var(&master->env_clone, cur_cmd->args[i]) == 1)
		{
			free_tab(master->env);
			master->env = clone_tab_env(master->env_clone, 0);
		}
		i++;
	}
}
