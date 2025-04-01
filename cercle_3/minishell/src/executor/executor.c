/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:40:23 by daavril           #+#    #+#             */
/*   Updated: 2025/04/01 16:42:46 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**clone_tab_env(t_clone *env, int size)
{
	char	**tab;
	t_clone	*cur;
	int		i;

	if (!env)
		return (NULL);
	cur = env;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	cur = env;
	while (cur)
	{
		tab[i] = ft_strdup(cur->value);
		cur = cur->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	execute_builtins(t_master *master, t_cmd *cur_cmd, int f)
{
	printf("BUILTIN GO\n");
	if (cur_cmd->builtins == ECHO)
		ft_echo(cur_cmd, 0, master);
	else if (cur_cmd->builtins == EXPORT)
		ft_export(master, cur_cmd);
	else if (cur_cmd->builtins == EXIT)
		ft_exit(master, cur_cmd, f);
	else if (cur_cmd->builtins == UNSET)
		ft_unset(master, cur_cmd);
	else if (cur_cmd->builtins == ENV)
		ft_env(master);
	else if (cur_cmd->builtins == PWD)
		ft_pwd();
	else if (cur_cmd->builtins == CD)
		ft_cd(master, cur_cmd);
}

int	executor(t_master *master)
{
	t_cmd	*cur;
	int		status1;

	cur = master->cmd_list;
	status1 = 0;
	master->env = clone_tab_env(master->env_clone, 0);
	if (!cur->next && !cur->prev && (cur->builtins == 3 || (cur->builtins == 5
				&& cur->args[1]) || cur->builtins == 6 || cur->builtins == 8))
		execute_builtins(master, cur, 1);
	else if (!cur->next && !cur->prev)
		do_cmd_solo(master, cur, master->env, status1);
	else if (cur->next && !cur->prev)
		do_cmd(master, cur, master->env, -1);
	return (0);
}
