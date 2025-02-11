/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:14 by abastian          #+#    #+#             */
/*   Updated: 2025/02/11 15:34:29 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*extract_word(char *input)
{
	char	*value;
	int		i;

	i = 0;
	while (input[i] && !is_whitespace(input[i])
		&& !is_special_char(input[i]) && !is_quote(input[i]))
		i++;
	value = malloc(sizeof(char) * (i + 1));
	if (!value)
		return (NULL);
	ft_strlcpy(value, input, i + 1);
	return (value);
}

int	word_len(char *input, t_token **token_list)
{
	int		i;
	t_token	*current;

	current = *token_list;
	i = 0;
	while (current->next)
		current = current->next;
	while (input[i] && !is_whitespace(input[i])
		&& !is_special_char(input[i]) && !is_quote(input[i]))
		i++;
	if (input[i] == ' ')
		current->space = 1;
	return (i);
}
