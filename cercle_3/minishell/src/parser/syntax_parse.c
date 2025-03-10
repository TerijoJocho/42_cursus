/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:23:17 by abastian          #+#    #+#             */
/*   Updated: 2025/03/10 14:25:29 by daavril          ###   ########.fr       */
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
		if (current->type == 2 && current->real != PIPE && current->next->type == 2)
			return (1); //operateur suivi d'un operateur = KO || a voir mdr lol
		current = current->next;
	}
	if (!current->next && current->type == 2)
		return (1); // caractere special en fin de string = KO | PAS BON
	return (0);
}

