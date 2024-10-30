/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:24:25 by daavril           #+#    #+#             */
/*   Updated: 2024/10/22 12:28:32 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_ber_file(const char *argv)
{
	int		res;
	char	*str;

	res = 0;
	str = ft_strrchr(argv, '.');
	if (str)
		res = ft_strncmp(str, ".ber", 5);
	if (res != 0)
	{
		ft_printf("Error.\nNot a .ber file.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_game	game;

	if (argc == 2 || envp[0] != NULL)
	{
		is_ber_file(argv[1]);
		init_game(&game, argv[1]);
		init_img(&game);
	}
	return (0);
}
