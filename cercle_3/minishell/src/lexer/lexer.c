/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:10:37 by daavril           #+#    #+#             */
/*   Updated: 2025/04/07 11:26:15 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_token_list(t_token **token_list, int type, char *value)
{
	t_token	*new_token;

	if (!value)
		return ;
	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		free(new_token);
		return ;
	}
	new_token->value = value;
	new_token->value_2 = NULL;
	new_token->type = type;
	new_token->quote_flag = 0;
	new_token->double_quote = 0;
	new_token->space = 0;
	new_token->prev = NULL;
	new_token->next = NULL;
	if (!new_token)
		return ;
	add_token_back(token_list, new_token);
}

int	check_quote(char *input)
{
	int		i;
	char	c;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			c = input[i];
			if (input[i + 1])
				i++;
			else
				return (0);
			while (input[i] && input[i] != c)
			{
				i++;
				if (!input[i])
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	lexer_next(char *input, t_token **token_list, int *i)
{
	if (is_whitespace(input[*i]))
		(*i)++;
	else if (is_special_char(input[*i]))
	{
		if (input[*i + 1] && input[*i + 2] && is_special_char(input[*i + 2])
			&& !is_whitespace(input[*i + 1]) // ICI
			&& !ft_isalpha((char)input[*i + 1]))
			return (1);
		add_token_list(token_list, 2, extract_special_char(&input[*i]));
		(*i) += special_char_len(&input[*i], token_list);
	}
	else if (input[*i] == '\'' || input[*i] == '\"')
	{
		add_token_list(token_list, 3, extract_quoted_string(&input[*i],
				input[*i]));
		(*i) += quoted_string_len(&input[*i], token_list);
	}
	else
	{
		add_token_list(token_list, 1, extract_word(&input[*i]));
		(*i) += word_len(&input[*i], token_list);
	}
	return (0);
}

int	lexer(char *input, t_token **token_list)
{
	int	i;

	i = 0;
	if (!check_quote(input))
		return (1);
	while (input[i])
	{
		if (lexer_next(input, token_list, &i) == 1)
			return (1);
	}
	get_special_type(token_list);
	return (0);
}
