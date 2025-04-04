/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:28:46 by abastian          #+#    #+#             */
/*   Updated: 2025/04/05 01:03:45 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_outfile(t_token *token)
{
	char	**tab;
	t_token	*cur;
	int		i;

	cur = token;
	i = 0;
	while (cur && cur->real != PIPE)
	{
		if (cur->real == REDIR_OUT || cur->real == APPEND)
			i++;
		cur = cur->next;
	}
	tab = ft_calloc(i + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_infile(t_token *token)
{
	char	**tab;
	t_token	*cur;
	int		i;

	cur = token;
	i = 0;
	while (cur && cur->real != PIPE)
	{
		if (cur->real == REDIR_IN)
			i++;
		cur = cur->next;
	}
	tab = ft_calloc(i + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_heredoc(t_token *token)
{
	char	**tab;
	t_token	*cur;
	int		i;

	cur = token;
	i = 0;
	while (cur && cur->real != PIPE)
	{
		if (cur->real == HEREDOC)
			i++;
		cur = cur->next;
	}
	tab = ft_calloc(i + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

void	init_cmd_list_2(t_cmd **cmd, int i, t_token *token)
{
	(*cmd)->args = ft_calloc(i + 1, sizeof(char *));
	if (!(*cmd)->args)
	{
		perror("error alloc init_cmd_list_2");
		return ;
	}
	(*cmd)->infile = ft_infile(token);
	(*cmd)->outfile = ft_outfile(token);
	(*cmd)->path = NULL;
	(*cmd)->append = ft_append(token);
	(*cmd)->nb_heredoc = 0;
	(*cmd)->heredoc = ft_heredoc(token);
	(*cmd)->link = ft_heredoc(token);
	(*cmd)->next = NULL;
	(*cmd)->prev = NULL;
	(*cmd)->error = 0;
	if (token && token->real >= 2 && token->real <= 8)
		(*cmd)->builtins = token->real;
	else
		(*cmd)->builtins = 0;
}

void	init_cmd_list(t_master **master, int i)
{
	t_token	*cur;
	t_cmd	*new_cmd;
	t_token	*head;

	cur = (*master)->token_list;
	while (cur)
	{
		i = 1;
		head = cur;
		while (cur->next && cur->next->type != 2)
		{
			i++;
			cur = cur->next;
		}
		while (cur->next && cur->real != PIPE)
			cur = cur->next;
		new_cmd = malloc(sizeof(t_cmd));
		if (!new_cmd)
			return ;
		ft_bzero(new_cmd, sizeof(t_cmd));
		init_cmd_list_2(&new_cmd, i, head);
		cmd_add_back(master, new_cmd);
		cur = cur->next;
	}
}
