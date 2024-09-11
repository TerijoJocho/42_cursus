/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:24:25 by daavril           #+#    #+#             */
/*   Updated: 2024/09/11 16:09:47 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return  (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Touche : %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_data	data;
	t_image	image;
	int	x = 16;
	int	y = 16;

	data.mlx_ptr= mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	image.x = &x;
	image.y = &y;
	image.xpm_ptr = mlx_xpm_file_to_image(data.mlx_ptr, WALL_XPM, image.x,image.y);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, image.xpm_ptr, 25, 25);
	

	mlx_loop(data.mlx_ptr);


	return(0);
}
