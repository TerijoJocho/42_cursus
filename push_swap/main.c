/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:01:08 by daavril           #+#    #+#             */
/*   Updated: 2024/10/22 16:53:58 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!*str)
			return (0);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > 2147483647))
			return (0);
		if ((sign == -1 && res > 2147483648))
			return (0);
		str++;
	}
	return (1);
}

void	check_param(char *str, t_list **pile_a, char **tab)
{
	if (!is_int(str))
		error_mes("Parameter aren't integer or a number.\n", pile_a, tab);
	init_lst(str, pile_a, tab);
}

int	main(int argc, char **argv)
{
	char	**tab;
	t_list	*pile_a;
	t_list	*pile_b;
	int		i;

	i = 0;
	pile_a = NULL;
	pile_b = NULL;
	tab = NULL;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		while (tab[i])
			check_param(tab[i++], &pile_a, tab);
	}
	else if (argc > 2)
	{
		while (argv[++i])
			check_param(argv[i], &pile_a, tab);
	}
	if (!sorted(&pile_a))
		push_swap(&pile_a, &pile_b);
	free_all(tab, &pile_a, &pile_b, argc);
	exit(EXIT_SUCCESS);
	return (0);
}
