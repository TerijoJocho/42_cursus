/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_special_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:10 by abastian          #+#    #+#             */
/*   Updated: 2025/03/06 16:09:12 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

int	special_char_len(char *input, t_token **token_list)
{
	int		i;
	char	c;
	t_token	*current;

	current = *token_list;
	i = 0;
	c = input[i];
	while (current->next)
		current = current->next;
	if (c == '|')
		i++;
	else
	{
		while (input[i] && input[i] == c && i <= 2)
			i++;
	}
	if (input[i] == ' ')
		current->space = 1;
	return (i);
}
