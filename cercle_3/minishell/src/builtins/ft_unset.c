/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:20:04 by daavril           #+#    #+#             */
/*   Updated: 2025/03/24 15:16:31 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*cherche dans la liste chainee le VAR a supp, le supp mdr
* rattacher les neouds entre eux puis appeler clone_tab_env
* pour mettre a jour le tab **env
*/

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

int	search_var(t_master *master, t_cmd *cc)
{
	t_clone	*ec;
	t_clone	*next;
	int	flag;

	ec = master->env_clone;
	flag = 0;
	while (ec)
	{
		next = ec->next;
		if (ft_strncmp(ec->value, cc->args[1], ft_strlen(cc->args[1])) == 0 && ec->value[ft_strlen(cc->args[1])] == '=')
		{
			delete_node(&master->env_clone, ec);
			flag = 1;
		}
		ec = next;
	}
	return (flag);
}

void	ft_unset(t_master *master, t_cmd *cur_cmd)
{
	if (!cur_cmd->args[1])
	{
		printf("unset : missing argument\n");
		return ;
	}
	if (cur_cmd->args[2])
	{
		printf("unset : too many arguments\n");
		return ;
	}
	if (search_var(master, cur_cmd) == 0)
		printf("unset : no such variable: %s\n", cur_cmd->args[1]);
	//free master->env
	master->env = clone_tab_env(master->env_clone);
}
