/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:15:08 by daavril           #+#    #+#             */
/*   Updated: 2025/04/01 16:17:03 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_export(char *arg)
{
	int	i;

	i = 0;
	if (!arg || arg[0] == '=')
	{
		printf("export: %s : not a valid identifier\n", arg);
		return (1);
	}
	while (arg[i])
	{
		if (arg[i] == '=')
			return (2);
		i++;
	}
	return (0);
}

void	sort_export_list(t_clone **list)
{
	t_clone	*cur;
	t_clone	*next;
	char	*tmp;
	int		sorted;

	if (!list || !*list)
		return ;
	while (!sorted)
	{
		sorted = 1;
		cur = *list;
		while (cur->next)
		{
			next = cur->next;
			if (ft_strncmp(cur->value, next->value, ft_strlen(cur->value)) > 0)
			{
				tmp = cur->value;
				cur->value = next->value;
				next->value = tmp;
				sorted = 0;
			}
			cur = cur->next;
		}
	}
}
