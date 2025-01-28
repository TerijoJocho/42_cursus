/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_special_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:20 by abastian          #+#    #+#             */
/*   Updated: 2025/01/28 15:29:17 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	choose_real(char *value, t_real *real)
{
	if (ft_strncmp(value, "|", 1) == 0)
		*real = PIPE;
	else if (ft_strncmp(value, "<<", 2) == 0)
		*real = HEREDOC;
	else if (ft_strncmp(value, ">>", 2) == 0)
		*real = APPEND;
	else if (ft_strncmp(value, "<", 1) == 0)
		*real = REDIR_IN;
	else if (ft_strncmp(value, ">", 1) == 0)
		*real = REDIR_OUT;
}

void	get_special_type(t_token **token_list)
{
	t_token	*current;

	current = *token_list;
	while (current)
	{
		if (current->type == 1)
			current->real = WORD;
		else if (current->type == 2)
			choose_real(current->value, &current->real);
		else
			current->real = STRING;
		current = current->next;
	}
}
