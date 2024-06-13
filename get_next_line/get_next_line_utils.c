/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:45 by daavril           #+#    #+#             */
/*   Updated: 2024/06/13 18:35:24 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_clean_stash(char *stash)
{
	while (*stash)
	{
		if (*stash == '\n')
			return (1);
		stash++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	c;
	int				len;

	if (nmemb && size > 4294967295 / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	len = nmemb * size;
	c = '0';
	while (len--)
		*((unsigned char *)(ptr + len)) = c;
	return (ptr);
}

char	*ft_line(char *stash)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static size_t	funct_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*join buffer a stash*/
char	*ft_put_buf_in_stash(char *buffer, char *stash)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char *)malloc(sizeof(*ptr) * (funct_strlen(buffer)
				+ funct_strlen(stash) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[i] && stash)
		ptr[j++] = stash[i++];
	i = 0;
	while (buffer[i])
		ptr[j++] = buffer[i++];
	ptr[j] = '\0';
	free(stash);
	return (ptr);
}
