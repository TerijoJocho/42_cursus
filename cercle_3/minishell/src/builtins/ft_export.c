/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:08:47 by daavril           #+#    #+#             */
/*   Updated: 2025/03/27 11:24:28 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		is_export(char *arg)
{
	int	i;

	i = 0;
	if (!arg || arg[0] == '=')
	{
		printf("export: %s : not a valid identifier\n", arg);
		return (1);
	}
	while (arg[i])
	{
		if (arg[i] == '=')
			return (2);
		i++;
	}
	return (0);
}

void	sort_export_list(t_clone **list)
{
	t_clone	*cur;
	t_clone	*next;
	char	*tmp;
	int		sorted;

	if (!list || !*list)
		return ;
	while (!sorted)
	{
		sorted = 1;
		cur = *list;
		while (cur->next)
		{
			next = cur->next;
			if (ft_strncmp(cur->value, next->value, ft_strlen(cur->value)) > 0)
			{
				tmp = cur->value;
				cur->value = next->value;
				next->value = tmp;
				sorted = 0;
			}
			cur = cur->next;
		}
	}
}

void	display_export(t_clone *ex_lst)
{
	t_clone	*cur;
	char	*equal_sign;
	char	*name;
	char	*value;

	sort_export_list(&ex_lst);
	cur = ex_lst;
	while (cur)
	{
		equal_sign = ft_strchr(cur->value, '=');
		if (equal_sign)
		{
			name = ft_substr(cur->value, 0, equal_sign - cur->value);
			value = equal_sign + 1;
			printf("export %s=\"%s\"\n", name, value);
			free(name);
		}
		else
			printf("export %s\n", cur->value);
		cur = cur->next;
	}
}

t_clone	*find_var(t_clone *list, char *arg)
{
	t_clone	*cur;
	int		len;
	int		cur_len;

	cur = list;
	len = 0;
	while (arg[len] && arg[len] != '=')
		len++;
	while (cur)
	{
		cur_len = 0;
		while (cur->value[cur_len] && cur->value[cur_len] != '=')
			cur_len++;
		if (cur_len == len && ft_strncmp(cur->value, arg, len) == 0)
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
	free(name);
	if (existing)
	{
		free(existing->value);
		existing->value = ft_strdup(arg);
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
	if (ex_val == 1)
		return ;
	else if (ex_val == 2)
	{
		add_it(&master->env_clone, arg, 0);
		free_tab(master->env);
		master->env = clone_tab_env(master->env_clone, 0);
		add_it(&master->export_list, arg, 0);
	}
	else if (ex_val == 0)
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
