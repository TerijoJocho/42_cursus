/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_quoted_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:03 by abastian          #+#    #+#             */
/*   Updated: 2025/02/11 15:32:48 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*extract_quoted_string(char *input, char quote)
{
	char	*value;
	int		i;

	i = 1;
	while (input[i] && input[i] != quote)
		i++;
	if (input[i] != quote)
		return (NULL); // erreur
	value = malloc(sizeof(char) * i);
	if (!value)
		return (NULL);
	ft_strlcpy(value, &input[1], i);
	return (value);
}

int	quoted_string_len(char *input, t_token **token_list)
{
	int		i;
	t_token	*current;

	i = 1;
	current = *token_list;
	while (current->next)
		current = current->next;
	if (input[0] == '\'')
		current->quote_flag = 1;
	while (input[i] && input[i] != input[0])
		i++;
	if (input[i] == input[0])
		i++;
	if (input[i] == ' ')
		current->space = 1;
	return (i);
}
