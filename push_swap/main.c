/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:01:08 by daavril           #+#    #+#             */
/*   Updated: 2024/10/01 18:06:53 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_mes(char *str)
{
	ft_printf("Error.\n%s",str);
	exit(EXIT_FAILURE);
}

int	is_num(char *str)
{
	while(*str)
	{
		/*if (*str == '-' || *str == '+')
			str++;*/
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

int	is_int(char *str)
{
	long long	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while(*str)
	{
		res = res * 10 + (*str + '0');
		ft_printf("prout :%d\n",res);
		if ((sign == 1 && res > 2147483647) || (sign == -1 && res < -2147483648))
				return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	t_list	*pile_a;
	t_list	*pile_b;

	i = 1;
	(void)argc;
	pile_a = ft_lstnew((void *)(__intptr_t)ft_atoi(argv[i]));
	while (argv[++i])
	{
		/*if (!is_num(argv[i]))
			error_mes("Parameter aren't numbers.\n");
		if (!is_int(argv[i]))
			error_mes("Parameter aren't integer.\n");
		if(is_double(argv[i]))
			error_mes("There is a parameter twice.");*/
		init_lst(argv[i], pile_a);
	}
	pile_b = NULL;
	swap_a(&pile_a);
	push_b(&pile_a, &pile_b);
	while (pile_a)
	{
		ft_printf("Value a: %d\n", (int)(__intptr_t)pile_a->content);
		pile_a = pile_a->next;
	}
	while (pile_b)
	{
		ft_printf("Value b: %d\n", (int)(__intptr_t)pile_b->content);
		pile_b = pile_b->next;
	}
	return (0);
}
