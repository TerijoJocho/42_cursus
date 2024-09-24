/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:24:25 by daavril           #+#    #+#             */
/*   Updated: 2024/09/24 17:04:46 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_ber_file(const char *argv, t_game *game)
{
	char	*str;

	str = ft_strrchr(argv, '.');
	if (str)
		return(ft_strncmp(str, ".ber", 5) == 0);
	/*fonctionne pas et flemme de faire mtn*/
	error_message("Not a .ber file.", game);
	/*-----------------------------------------*/
	return (1);
}
void	game_over(t_game *game)
{
	ft_printf("Game closed.");
	free(game->map.grille);
	free(game->map.grille_clone);
	free(game->mlx_ptr);
	free(game->win_ptr);
	free(game->wall_xpm);
	free(game->coins_xpm);
	free(game->exit_xpm);
	free(game->open_xpm);
	free(game->charac_xpm);
	free(game->floor_xpm);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 && (is_ber_file(argv[1], &game)))
	{
		init_game(&game, argv[1]); //init_map nan?
		init_img(&game);
		//move(&game);
	}
	/*else if (argc == 2 && !(is_ber_file(argv[1])))
		end_game();
	else if (argc < 2)
		end_game();
	else
		end_game();*/
	return(0);
}
