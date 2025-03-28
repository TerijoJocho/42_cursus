/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:23:17 by abastian          #+#    #+#             */
/*   Updated: 2025/03/27 12:35:42 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int	syntax_check(t_token **token_list)
{
	t_token	*current;

	current = *token_list;
	if (current->real == PIPE) // autre carac ? a voir
		return (1);
	if (ft_strchr(current->value, ';'))
		return (1);
	if (ft_strchr(current->value, '&'))
		return (1);
	while (current->next)
	{
		if (current->type == 2 && current->next->type == 2)
			return (1); //operateur suivi d'un operateur = KO || a voir mdr lol
		current = current->next;
	}
	if (!current->next && current->type == 2)
		return (1); // caractere special en fin de string = KO | PAS BON
	return (0);
}

void	cmd_add_back(t_master **master, t_cmd *node)
{
	t_cmd	**list;
	t_cmd	*last;

	list = &(*master)->cmd_list;
	last = NULL;
	while (*list)
	{
		last = *list;
		list = &(*list)->next;
	}
	*list = node;
	node->prev = last;
}

int	*ft_append(t_token *token)
{
	int	*tab;
	t_token	*cur;
	int	i;

	cur = token;
	i = 0;
	while (cur && cur->real != PIPE)
	{
		if (cur->real == REDIR_OUT || cur->real == APPEND)
			i++;
		cur = cur->next;
	}
	tab = ft_calloc(i + 1, sizeof(int));
	if (!tab)
		return (NULL);
	return (tab);
}

int	check_is_expand(t_token **token_list, t_clone **env)
{
	t_token	*current;
	char	*cpy;

	current = *token_list;
	while (current)
	{
		cpy = ft_strdup(current->value);
		if (current->is_expand == 1)
		{
			if (!expand_string(current, env, cpy))
				return (1);
		}
		current = current->next;
		free(cpy);
	}
	return (0);
}
