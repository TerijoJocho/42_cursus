/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:35:51 by daavril           #+#    #+#             */
/*   Updated: 2024/09/12 14:14:29 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	len--;
	while (n)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	int n;

	n = -200;
	while (n <= 200)
	{
		printf("int :%d\n", n);
		printf("str :%s\n", ft_itoa(n));
		n++;
	}
	return (0);
}*/
