/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:20:32 by daavril           #+#    #+#             */
/*   Updated: 2024/06/13 17:20:39 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	while (fd)
	{
		get_next_line(fd);
		fd--;
	}
	close(fd);
	return (0);
}
