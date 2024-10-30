/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:10:48 by daavril           #+#    #+#             */
/*   Updated: 2024/05/15 14:05:21 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
		return (NULL);
	array = (int *)malloc(sizeof(int) * ((max - min) + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (min <= max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}
/*#include <stdio.h>
int	main(void)
{
	int min = 5;
	int max = 100;
	int *result = ft_range(min, max);

	if (!result)
	{
		printf("Erreur: Impossible d'allouer de la mémoire\n");
		return (1);
	}

	printf("Tableau généré : ");
	for (int i = 0; i <= max - min; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	free(result);
	return (0);
}*/
