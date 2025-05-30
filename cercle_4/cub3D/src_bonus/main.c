/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:39:08 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 20:06:52 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_game	game;

	if (argc != 2)
		return (printf("error: wrong number of arguments\n"), 1);
	if (ft_init_game(&game, argv[1]))
		return (ft_clean_parse(&game, 1), 1);
	if (ft_is_cub(game.file_name))
		return (ft_clean_parse(&game, 1), 1);
	if (ft_get_file(&game))
		return (ft_clean_parse(&game, 1), 1);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (0);
	game.wdw = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (game.wdw == NULL)
		ft_clean(&game);
	if (ft_define_img(&game))
		return (ft_clean(&game), 1);
	ft_init_splayer(&game);
	mlx_hook(game.wdw, KeyPress, KeyPressMask, ft_key_press, &game);
	mlx_hook(game.wdw, KeyRelease, KeyReleaseMask, ft_key_release, &game);
	mlx_loop_hook(game.mlx, ft_keys_loop_bonus, &game);
	mlx_hook(game.wdw, 17, 1L << 17, &ft_clean, &game);
	mlx_loop(game.mlx);
	return (ft_clean(&game), 0);
}
