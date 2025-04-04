/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:38:05 by daavril           #+#    #+#             */
/*   Updated: 2025/04/04 22:48:35 by daavril          ###   ########.fr       */
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
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	cmd_clear_2(t_cmd **cur)
{
	if ((*cur)->args)
		free_tab((*cur)->args);
	if ((*cur)->infile)
		free_tab((*cur)->infile);
	if ((*cur)->outfile)
		free_tab((*cur)->outfile);
	if ((*cur)->heredoc)
		free_tab((*cur)->heredoc);
	if ((*cur)->link)
		free_tab((*cur)->link);
	if ((*cur)->path)
		free((*cur)->path);
	if ((*cur)->append)
		free((*cur)->append);
}

void	cmd_clear(t_cmd **lst)
{
	t_cmd	*cur;
	t_cmd	*tmp;

	cur = *lst;
	while (cur)
		cur = cur->next;
	cur = *lst;
	while (cur)
	{
		tmp = cur->next;
		cmd_clear_2(&cur);
		free(cur);
		cur = tmp;
	}
	*lst = NULL;
}
