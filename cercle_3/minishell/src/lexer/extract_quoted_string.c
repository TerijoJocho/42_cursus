/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_quoted_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:03 by abastian          #+#    #+#             */
/*   Updated: 2025/01/28 15:28:18 by abastian         ###   ########.fr       */
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

int	quoted_string_len(char *input)
{
	int	i;

	i = 1;
	while (input[i] && input[i] != input[0])
		i++;
	if (input[i] == input[0])
		i++;
	return (i);
}
