/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:39:08 by daavril           #+#    #+#             */
/*   Updated: 2025/05/05 14:39:12 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./cube3D maps/file.cub
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cube3D maps/file_for_bonus.cub
#include "../includes/cube3d.h"

/**
 * @brief   Check if the file has a `.cub` extension.
 *
 * @param   argv Name of the file to check.
 * @return  0 if the file is a valid `.cub`, 1 otherwise (and prints an error).
 */
int	ft_is_cub(char *argv)
{
	char	*str;

	str = ft_strrchr(argv, '.');
	if (!str)
		return (printf("error: not a .cub file\n"), 1);
	if (ft_strncmp(str, ".cub", 5))
		return (printf("error: not a .cub file\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		return (printf("error: argument missing\n"), 1);
	else if (argc > 2)
		return (printf("error: too much arguments\n\n"), 1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (printf("error: malloc\n"), 1);
	ft_init_game(game, argv[1]);
	if (ft_is_cub(game->file_name))
		return (ft_clean(game), 1);
	if (ft_get_file(game))
		return (ft_clean(game), 1);
	ft_clean(game);
	return (0);
}
