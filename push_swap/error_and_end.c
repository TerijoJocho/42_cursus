/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:38:53 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 15:50:27 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_mes(char *str)
{
	ft_printf("Error.\n%s", str);
	exit(EXIT_FAILURE);
}

void	free_lst(t_list **pile)
{
	t_list	*temp;

	while (*pile)
	{
		temp = (*pile)->next;
		free(*pile);
		*pile = temp;
	}
	*pile = NULL;
	temp = NULL;
}

void	free_all(char **tab, t_list **pile_a, t_list **pile_b, int argc)
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		free_lst(pile_a);
		free_lst(pile_b);
	}
	else
	{
		free_lst(pile_a);
		free_lst(pile_b);
	}
}
