/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:14 by abastian          #+#    #+#             */
/*   Updated: 2025/01/28 15:29:02 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*extract_word(char *input)
{
	char	*value;
	int		i;

	i = 0;
	while (input[i] && !is_whitespace(input[i]) && !is_special_char(input[i]))
		i++;
	value = malloc(sizeof(char) * (i + 1));
	if (!value)
		return (NULL);
	ft_strlcpy(value, input, i + 1);
	return (value);
}

int	word_len(char *input)
{
	int	i;

	i = 0;
	while (input[i] && !is_whitespace(input[i]) && !is_special_char(input[i]))
		i++;
	return (i);
}
