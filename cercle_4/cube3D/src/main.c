

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
		return (1);
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
	ft_is_cub(game->file_name);
	ft_get_file(game);
	ft_clean(game);
	return (0);
}
