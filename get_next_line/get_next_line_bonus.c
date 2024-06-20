/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:44:47 by daavril           #+#    #+#             */
/*   Updated: 2024/06/20 15:17:49 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(void)
{
	get_next_line(-42);
}

char	*get_new_stash_and_right_line(char *line)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	new_stash = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	if (*new_stash == '\0')
	{
		free(new_stash);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (new_stash);
}

char	*read_and_stash(int fd, char *stash, char *buffer)
{
	int		bytes_size;
	char	*temp;

	bytes_size = 1;
	while (bytes_size > 0)
	{
		bytes_size = read(fd, buffer, BUFFER_SIZE);
		if (bytes_size < 0)
		{
			free(stash);
			return (NULL);
		}
		else if (bytes_size == 0)
			break ;
		buffer[bytes_size] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;
	char		*buffer;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
	{
		if (stash[fd] && fd >= 0 && fd < OPEN_MAX)
			free(stash[fd]);
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || read(fd, buffer, 0) < 0)
	{
		free(stash[fd]);
		free(buffer);
		stash[fd] = NULL;
		return (NULL);
	}
	line = read_and_stash(fd, stash[fd], buffer);
	free(buffer);
	if (!line)
		return (NULL);
	stash[fd] = get_new_stash_and_right_line(line);
	return (line);
}
