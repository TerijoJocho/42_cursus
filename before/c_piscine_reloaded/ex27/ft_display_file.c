/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:10 by daavril           #+#    #+#             */
/*   Updated: 2024/05/16 17:54:56 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	c;

	if (argc != 2)
	{
		if (argc == 1)
			write(1, "File name missing.", 19);
		else if (argc > 2)
			write(1, "Too many arguments.", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.", 18);
		return (1);
	}
	while (read(fd, &c, 1) == 1)
	{
		write(1, &c, 1);
	}
	close(fd);
	return (0);
}
