/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:38:05 by daavril           #+#    #+#             */
/*   Updated: 2025/03/25 13:37:16 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
void	cmd_clear(t_cmd **lst) // CONDITIONNAL JUMP ??? VOIR CHATGPT 10 MARS 2025 // +1 dans cmd_init !!!
{
	t_cmd	*cur;
	t_cmd	*tmp;

	cur = *lst;
	while (cur)
	{
		tmp = cur->next;
		if (cur->args)
			free_tab(cur->args);
		if (cur->infile)
			free_tab(cur->infile);
		if (cur->outfile)
			free_tab(cur->outfile);
		if (cur->heredoc)
			free_tab(cur->heredoc);
		if (cur->link)
			free_tab(cur->link);
		if (cur->path)
			free(cur->path);
		if (cur->append)
			free(cur->append);
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
