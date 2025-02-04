/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_special_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:10 by abastian          #+#    #+#             */
/*   Updated: 2025/01/28 15:28:44 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_sequence(char *input, char *sequence)
{
	int	i;

	i = 0;
	while (sequence[i])
	{
		if (input[i] != sequence[i])
			return (0);
		i++;
	}
	return (1);
}

char	*extract_special_char(char *input)
{
	char	*value;

	if (is_sequence(input, ">>"))
		return (ft_strdup(">>"));
	if (is_sequence(input, "<<"))
		return (ft_strdup("<<"));
	value = malloc(sizeof(char) * 2);
	if (!value)
		return (NULL);
	value[0] = input[0];
	value[1] = '\0';
	return (value);
}

int	special_char_len(char *input)
{
	if (is_sequence(input, "<<") || is_sequence(input, ">>"))
		return (2);
	return (1);
}
