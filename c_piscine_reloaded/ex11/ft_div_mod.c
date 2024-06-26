/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:07:53 by terijo            #+#    #+#             */
/*   Updated: 2024/05/15 13:56:39 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*int     main(void)
{
	int     *ptr1;
	int     *ptr2;
	int     a;
	int     b;
	int     div;
	int     mod;

	a = 4;
	b = 4;
	ptr1 = &div;
	ptr2 = &mod;
	printf("%d, %d\n", a, b);
	ft_div_mod(a, b, ptr1, ptr2);
	printf("div =%d, mod =%d", div, mod);
	return (0);
}*/