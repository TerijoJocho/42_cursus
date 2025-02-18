/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:09:11 by abastian          #+#    #+#             */
/*   Updated: 2025/02/18 15:10:40 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void	extract_expand(char *str, t_token *token)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	token->value_2 = ft_strdup(&str[i+1]); //prevoir free
	printf("%s\n", token->value_2);
}

int	expand_arg(t_token *token, t_clone **env)
{
	int	i;
	char buffer[70000]; //idee en attendant
	t_clone	*cur_env;

	i = -1;
	cur_env = *env;
	if (token->value[0] != '$')
		return (printf("Fatal expand error\n"), 0);
	while (token->value[++i])
		buffer[i] = token->value[i + 1];
	buffer[i] = '\0';
	while (cur_env)
	{
		if (ft_strncmp(cur_env->value, buffer, i - 1) == 0 &&
				cur_env->value[i - 1] == '=')
		{
			extract_expand(cur_env->value, token);
			return (1);
		}
		cur_env = cur_env->next;
	}
	return (0);
}
