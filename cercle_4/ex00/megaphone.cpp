/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:00:38 by terijo            #+#    #+#             */
/*   Updated: 2025/05/27 14:14:49 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

void	ft_upperCase(char *str)
{
	int		i;
	char	ch;

	i = 0;
	while (str[i])
	{
		ch = toupper(str[i]);
		std::cout << ch;
		i++;
	}
	return ;
}

void	ft_megaphone(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ft_upperCase(argv[i]);
		std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return ;
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_megaphone(&argv[1]);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
