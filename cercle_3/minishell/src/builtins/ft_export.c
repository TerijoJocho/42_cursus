/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:08:47 by daavril           #+#    #+#             */
/*   Updated: 2025/03/24 18:37:23 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_export(t_clone *ex_lst)
{
	t_clone	*cur;

	cur = ex_lst;
	while (cur)
	{
		printf("%s\n", cur->value);
		cur = cur->next;
	}
}

int		is_export(char *arg)
{
	int	i;

	i = 0;
	if (!arg || arg[0] == '=')
	{
		printf("export: %s : not a valid identifier\n", arg);
		return (2);
	}
	while (arg[i])
	{
		if (arg[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

t_clone	*find_var(t_clone *list, char *arg)
{
	t_clone	*cur;
	int		len;

	cur = list;
	len = 0;
	while (arg[len] && arg[len] != '=')
		len++;
	while (cur)
	{
		if (ft_strncmp(cur->value, arg, len) == 0 && cur->value[len] == '=')
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	add_it(t_clone **list, char *arg, int len)
{
	t_clone	*existing;
	t_clone	*new;
	char	*name;

	while (arg[len] && arg[len] != '=')
		len++;
	name = ft_substr(arg, 0, len);
	existing = find_var(*list, name);
	printf("value:%s\n", existing->value);
	free(name);
	if (existing)
	{
		free(existing->value);
		existing->value = ft_strdup(arg);
		printf("value:%s\n", existing->value);
		return ;
	}
	new = malloc(sizeof(t_clone));
	if (!new)
		return ;
	new->value = ft_strdup(arg);
	new->next = *list;
	new->prev = NULL;
	if (*list)
		(*list)->prev = new;
	*list = new;
}

void	handle_export(t_master *master, char *arg)
{
	int	ex_val;

	ex_val = is_export(arg);
	if (ex_val == 2)
		return ;
	else if (ex_val == 0)
	{
		add_it(&master->env_clone, arg, 0);
		add_it(&master->export_list, arg, 0);
	}
	else if (ex_val == 1)
	{
		if (!find_var(master->export_list, arg))
			add_it(&master->export_list, arg, 0);
	}
}

void	ft_export(t_master *master, t_cmd *cur_cmd)
{
	int		i;

	i = 1;
	if (!cur_cmd->args[1])
	{
		display_export(master->export_list);
		return ;
	}
	while (cur_cmd->args[i])
	{
		handle_export(master, cur_cmd->args[i]);
		i++;
	}
}
