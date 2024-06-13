/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:58:17 by daavril           #+#    #+#             */
/*   Updated: 2024/06/13 18:52:52 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*stash;
	char		*buffer;
	char		*line;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !(buffer))
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		stash = ft_put_buf_in_stash(buffer, stash);
		if (ft_clean_stash(stash) == 1)
		{
			free(buffer);
			return (ft_line(stash));
		}
		free(buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read <= 0)
		return (free(buffer), NULL);
	return (line = ft_line(stash));
}

/*NB : si on a buf_size = 9999, il faut donc que mon ft_check_end_line
		regarde combien de \n il y a dans mon buffer et que mon
		ft_enleve_le_n_et_renvoie_la_ligne ???*/
