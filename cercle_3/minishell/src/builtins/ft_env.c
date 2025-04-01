/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:13:25 by daavril           #+#    #+#             */
/*   Updated: 2025/04/01 16:13:27 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(t_master *master)
{
	t_clone	*cur;

	cur = master->env_clone;
	if (!cur)
		return ;
	while (cur)
	{
		printf("%s\n", cur->value);
		cur = cur->next;
	}
}
