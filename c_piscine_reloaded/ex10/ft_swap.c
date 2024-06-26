/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:59:07 by terijo            #+#    #+#             */
/*   Updated: 2024/05/15 13:56:27 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}
/*int     main(void)
{
	int     *ptr1;
	int     *ptr2;
	int     a;
	int     b;

	ptr1 = &a;
	ptr2 = &b;
	a = 4;
	b = 5;
	printf("%d, %d", a, b);
	ft_swap(ptr1, ptr2);
	printf("; %d, %d", a, b);
	return (0);
}*/