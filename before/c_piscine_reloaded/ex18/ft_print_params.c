/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:29:31 by terijo            #+#    #+#             */
/*   Updated: 2024/05/16 13:51:21 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ft_putchar(argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		ft_print_params(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
