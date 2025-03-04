/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:38:05 by daavril           #+#    #+#             */
/*   Updated: 2025/03/04 14:22:21 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void	clean_env(t_clone **lst)
{
	t_clone	*current;
	t_clone	*tmp;

	current = *lst;
	while (current)
	{
		tmp = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

void	clean_values(t_token **lst)
{
	t_token	*current;

	current = *lst;
	while (current)
	{
		if (current->value != NULL)
			free(current->value);
		if (current->value_2 != NULL)
			free(current->value_2);
		current = current->next;
	}
}

void	cmd_clear(t_cmd **lst)
{
	t_cmd	*cur;
	t_cmd	*tmp;
	int	i;

	cur = *lst;
	while (cur)
	{
		i = 0;
		tmp = cur->next;
		while (cur->args[i])
		{
			free(cur->args[i]);
			i++;
		}
		if (cur->infile != NULL)
			free(cur->infile);
		if (cur->outfile != NULL)
			free(cur->outfile);
		if (cur->path != NULL)
			free(cur->path);
		free(cur);
		cur = tmp;
	}
	*lst = NULL;
}

void	free_all(t_master *master)
{
	clean_values(&master->token_list);
	token_clear(&master->token_list); //pour liberer tous les neeouds
	cmd_clear(&master->cmd_list);
}
