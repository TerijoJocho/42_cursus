/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:07:53 by abastian          #+#    #+#             */
/*   Updated: 2025/02/21 17:04:21 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*extract_expand_2(char *str)
{
	char	*new_value;
	int	i;

	i = 0;
	while (str[i])
		i++;
	new_value = malloc(sizeof(char) * (i + 1));
	if (!new_value)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_value[i] = str[i];
		i++;
	}
	new_value[i] = '\0';
	return (new_value);
}

char	*take_var(char *value, t_clone **env)
{
	char	*var;
	int	i;
	t_clone	*cur_env;

	i = 0;
	cur_env = *env;
	while (value[i] && value[i] != ' ' && value[i] != '$')
		i++;
	var = malloc(sizeof(char) * i + 2);
	i = 0;
	while (value[i] && value[i] != ' ' && value[i] != '$')
	{
		var[i] = value[i];
		i++;
	}
	var[i++] = '=';
	var[i] = '\0';
	while (cur_env)
	{
		if (ft_strncmp(cur_env->value, var, i - 1) == 0)
		{
			var = extract_expand_2(&cur_env->value[i]);
			return (var);
		}
		cur_env = cur_env->next;
	}
	return (NULL);
}

int	expand_string(t_token *token, t_clone **env, char *cpy)
{
	int	i;
	char	*new_value;
	char	*tmp;
	char	*var;

	i = 0;
	new_value = ft_strdup("");
	while (cpy[i])
	{
		if (cpy[i] == '$')
		{
			tmp = ft_strjoin(new_value, ft_substr(cpy, 0, i));
			free(new_value);
			new_value = tmp;
			i++;
			var = take_var(&cpy[i], env);
			if (!var)
				var = ft_strdup("");
			tmp = ft_strjoin(new_value, var);
			free(new_value);
			new_value = tmp;
			free(var);
			while (cpy[i] && (ft_isalnum(cpy[i])))
				i++;
			cpy += i;
			i = 0;
		}
		else
			i++;
	}
	token->value_2 = new_value;
	if (token->value_2 == NULL)
		return (0);
	return (1);
}

