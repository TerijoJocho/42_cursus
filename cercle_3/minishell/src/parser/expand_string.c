/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:07:53 by abastian          #+#    #+#             */
/*   Updated: 2025/03/06 16:12:01 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*extract_expand_2(char *str)
{
	char	*new_value;
	int		i;

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
	return (new_value); // mdr c'est juste un strdup fdp
}

char *take_var(char *value, t_clone **env, int i)
{
	char *var;
	t_clone *cur_env;

	cur_env = *env;
	while (value[i] && value[i] != ' ' && value[i] != '$')
		i++;
	var = malloc(sizeof(char) * (i + 2));
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
			free(var);
			return (extract_expand_2(&cur_env->value[i]));
		}
		cur_env = cur_env->next;
	}
	return (free(var), NULL);
}

char *expand_variable(char *cpy, char *new_value, t_clone **env, int *i)
{
	char *substr;
	char *tmp;
	char *var;

	substr = ft_substr(cpy, 0, *i);
	tmp = ft_strjoin(new_value, substr);
	free(substr);
	free(new_value);
	if (!tmp)
		return (NULL);
	new_value = tmp;
	(*i)++;
	var = take_var(&cpy[*i], env, 0);
	if (!var)
		var = ft_strdup("");
	tmp = ft_strjoin(new_value, var);
	free(new_value);
	free(var);
	if (!tmp)
		return (NULL);
	new_value = tmp;
	while (cpy[*i] && ft_isalnum(cpy[*i]))
		(*i)++;
	return (new_value);
}

void	add_tmp(char *new_value, char *tmp, t_token *token)
{
	char	*prev_value;

	prev_value = new_value;
	if (tmp != NULL)
	{
		new_value = ft_strjoin(prev_value, tmp);
		free(prev_value);
		free(tmp);
	}
	token->value_2 = new_value;
}

int expand_string(t_token *token, t_clone **env, char *cpy)
{
	int i;
	char *new_value;
	char	*tmp;

	i = 0;
	new_value = ft_strdup("");
	tmp =NULL;
	if (!new_value)
		return (0);
	while (cpy[i])
	{
		if (cpy[i] == '$')
		{
			new_value = expand_variable(cpy, new_value, env, &i);
			if (!new_value)
				return (0);
			cpy += i;
			tmp = ft_strdup(cpy);
			i = 0;
		}
		else
			i++;
	}
	add_tmp(new_value, tmp, token);
	return (1);
}

// VERSION ORIGINALE
// int	expand_string(t_token *token, t_clone **env, char *cpy)
// {
// 	int	i;
// 	char	*new_value;
// 	char	*tmp;
// 	char	*var;
// 	char	*substr;

// 	i = 0;
// 	new_value = ft_strdup("");
// 	if (!new_value)
// 		return (0);
// 	printf("value before expand_2: %s\n", cpy);
// 	while (cpy[i])
// 	{
// 		if (cpy[i] == '$')
// 		{
// 			substr = ft_substr(cpy, 0, i);
// 			printf("substr : %s\n", substr);
// 			tmp = ft_strjoin(new_value, substr);
// 			printf("tmp first: %s\n", tmp);
// 			free(substr);
// 			free(new_value);
// 			if (!tmp)
// 				return (0);
// 			new_value = tmp;
// 			printf("new_value first: %s\n", new_value);
// 			i++;
// 			var = take_var(&cpy[i], env, 0);
// 			if (!var)
// 				var = ft_strdup("");
// 			printf("VAR : %s\n", var);
// 			tmp = ft_strjoin(new_value, var);
// 			printf("tmp second : %s\n", tmp);
// 			free(new_value);
// 			free(var);
// 			if (!tmp)
// 				return (0);
// 			new_value = tmp;
// 			printf("new_value: %s\n", new_value);
// 			while (cpy[i] && (ft_isalnum(cpy[i])))
// 				i++;
// 			cpy += i;
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
// 	token->value_2 = new_value;
// 	return (1);
// }
