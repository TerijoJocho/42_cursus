/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:14:21 by abastian          #+#    #+#             */
/*   Updated: 2025/03/19 12:14:21 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_merge(t_token **token_list, t_token *cur, char *va_prev, char *va)
{
	char	*new_value;
	t_token	*to_delete;

	to_delete = cur->prev;
	new_value = ft_strjoin(va, va_prev);
	free(to_delete->value);
	free(cur->value);
	if (cur->value_2 && cur->value_2 != to_delete->value_2)
		// refaire des tests de valgrind
		free(cur->value_2);
	if (to_delete->value_2)
		free(to_delete->value_2);
	cur->value = ft_strdup(new_value);
	cur->value_2 = NULL;
	if (to_delete->is_expand || cur->is_expand)
		cur->is_expand = 1;
	if (to_delete->prev)
		to_delete->prev->next = cur;
	else
		*token_list = cur;
	cur->prev = to_delete->prev;
	free(to_delete);
	free(new_value);
}

void	merge_token(t_token **token_list)
{
	t_token	*cur;

	cur = *token_list;
	while (cur)
	{
		if (cur->prev && cur->prev->space == 0 && cur->prev->type != 2
			&& cur->type != 2)
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
