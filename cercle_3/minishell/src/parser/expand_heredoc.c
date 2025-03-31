/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:13:33 by abastian          #+#    #+#             */
/*   Updated: 2025/03/31 16:36:59 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_tmp_heredoc(char **new_value, char *tmp)
{
	char	*prev_value;

	prev_value = *new_value;
	if (tmp != NULL)
	{
		*new_value = ft_strjoin(prev_value, tmp);
		free(prev_value);
		free(tmp);
	}
}

char	*expand_heredoc(t_clone **env, char *input, int i)
{
	char	*new_value;
	char	*tmp;

	new_value = ft_strdup("");
	tmp = NULL;
	if (!new_value)
		return (NULL);
	while (input[i])
	{
		if (input[i] == '$')
		{
			new_value = expand_variable(input, new_value, env, &i);
			if (!new_value)
				return (0);
			input += i;
			if (tmp != NULL)
				free(tmp);
			tmp = ft_strdup(input);
			i = 0;
		}
		else
			i++;
	}
	add_tmp_heredoc(&new_value, tmp);
	return (new_value);
}
