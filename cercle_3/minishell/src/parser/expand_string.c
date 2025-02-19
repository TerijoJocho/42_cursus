/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:07:53 by abastian          #+#    #+#             */
/*   Updated: 2025/02/19 17:25:00 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*extract_expand_2(char *str, int j)
{
	char	*new_value;
	int	i;

	i = 0;
	while (str[i])
		i++;
	new_value = malloc(sizeof(char) * i - j);
	if (!new_value)
		return (NULL);
	i = 0;
	while (str[j])
	{
		new_value[i++] = str[j++];
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
			var = extract_expand_2(cur_env->value, i);
			return (var);
		}
		cur_env = cur_env->next;
	}
	return (NULL);
}

int	expand_string(t_token *token, t_clone **env)
{
	int	i;
	char	*before;
	char	*tmp;
	char	*var;
	char	*new_value;


	i = 0;
	tmp = NULL;
	var = NULL;
	before = NULL;
	new_value= NULL;
	while (token->value[i])
	{
		if (token->value[i] == '$')
		{
			if (new_value == NULL)
				before = ft_substr(token->value, 0, i);
			else
				before = ft_substr(new_value, 0, ft_strlen(new_value));
			printf("%s\n", before);
			i++;
			var = take_var(&token->value[i], env);
			if(!var)
				var = ft_strdup("");
			tmp = ft_strjoin(new_value, before);
			free(new_value);
			new_value = ft_strjoin(tmp, var);
			free(tmp);
			free(var);
		}
		else
			i++;
	}
	token->value_2 = new_value;
	printf("value_2: %s\n", token->value_2);
	printf("value_1: %s\n", token->value);
	if (token->value_2 == NULL)
		return (0);
	return (1);
}

