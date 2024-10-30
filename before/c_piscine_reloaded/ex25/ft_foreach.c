/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:34:41 by daavril           #+#    #+#             */
/*   Updated: 2024/05/15 16:49:41 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		f(tab[i]);
		i++;
	}
}
/*void    print_int(int num)
{
	printf("%d ",num);
}
int main (void)
{
	int tab[] = {1, 2, 3, 4, 5};
	int lenght = sizeof(tab) / sizeof(tab[0]);

	ft_foreach(tab, lenght, print_int);
}*/