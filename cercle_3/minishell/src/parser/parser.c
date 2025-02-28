/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:40:34 by daavril           #+#    #+#             */
/*   Updated: 2025/02/28 16:02:43 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int	check_is_expand(t_token **token_list, t_clone **env)
{
	t_token	*current;
	char	*cpy;

	current = *token_list;
	while (current)
	{
		cpy = ft_strdup(current->value);
		if (current->is_expand == 1)
		{
			if (!expand_string(current, env, cpy))
				return (1);
		}
		current = current->next;
		free(cpy);
	}
	return (0); // des int partout ? je pense que je me perds
}

void	do_merge(t_token **token_list, t_token *cur, char *va_prev, char *va)
{
	char	*new_value;
	t_token	*previous_one;

	new_value = ft_strjoin(va, va_prev);
	free(cur->prev->value);
	free(cur->value);
	if (cur->value_2)
		free(cur->value_2);
	if (cur->prev->value_2)
		free(cur->prev->value_2);
	cur->value = ft_strdup(new_value);
	free(new_value);
	if (cur->prev && cur->prev->prev)
		previous_one = cur->prev->prev;
	else
		previous_one = NULL;
	free(cur->prev);
	cur->prev = previous_one;
	if (cur->prev)
		cur->prev->next = cur;
	else
		*token_list = cur;
}

void	merge_token(t_token **token_list)
{
	t_token	*cur;

	cur = *token_list;
	while (cur)
	{
		if (cur->prev && cur->prev->space == 0 && cur->prev->type != 2 && cur->type != 2)
		{
			if (!cur->value_2 && !cur->prev->value_2)
				do_merge(token_list, cur, cur->value, cur->prev->value);
			else if (cur->value_2 && !cur->prev->value_2)
				do_merge(token_list, cur, cur->value_2, cur->prev->value);
			else if (!cur->value_2 && cur->prev->value_2)
				do_merge(token_list, cur, cur->value, cur->prev->value_2);
			else
				do_merge(token_list, cur, cur->value_2, cur->prev->value_2);
		}
		cur = cur->next;
	}
}

int	parser(t_master *master)
{
	if (check_is_expand(&master->token_list, &master->env_clone) == 1)
		return (printf("PROBLEME EXPAND\n"), 1);
	merge_token(&master->token_list);
	parse_cmd(&master);
	return (0);
}


// char *expand_variable(char *var_name) {
//     char *value = getenv(var_name);
//     if (value)
//         return ft_strdup(value);  // Si défini, retourner la valeur
//     return ft_strdup("");         // Sinon, retourner une string vide
// }
