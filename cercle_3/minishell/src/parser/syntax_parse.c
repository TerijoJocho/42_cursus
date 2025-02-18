/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:23:17 by abastian          #+#    #+#             */
/*   Updated: 2025/02/18 13:24:31 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int	syntax_check(t_token **token_list)
{
	t_token	*current;

	current = *token_list;
	if (current->type == 2)
		return (1); // caractere special en debut de string = KO
	while (current->next)
	{
		if (current->type == 2 &&
			current->next->real != ARG && current->next->real != STRING)
			return (1); //operateur non suivi d'un mot = KO
		current = current->next;
	}
	if (!current->next && current->type == 2)
		return (1); // caractere special en fin de string = KO
	return (0);
}

