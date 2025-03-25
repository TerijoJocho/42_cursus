/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:31:59 by abastian          #+#    #+#             */
/*   Updated: 2025/03/25 12:20:16 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int	make_heredoc_next(char *name)
{
	int	fd;

	fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

char	*check_tmp(int *tmp, int i, char **link)
{
	char	*tmp_name;
	int		tmp2;

	tmp2 = (*tmp);
	tmp_name = ft_itoa(tmp2);
	while (access(tmp_name, F_OK) == 0)
	{
		(*tmp)++;
		tmp2 = (*tmp);
		free(tmp_name);
		tmp_name = ft_itoa(tmp2);
	}
	(*tmp)++;
	link[i] = ft_strdup(tmp_name);
	return (tmp_name);
}

int	make_heredoc(char **heredoc, int *error, char **link)
{
	int		i;
	int		tmp;
	char	*name;

	tmp = 1;
	i = 0;
	name = NULL;
	if (!heredoc || !heredoc[0])
		return (1);
	while (heredoc[i])
	{
		name = check_tmp(&tmp, i, link);
		if (!name)
			return (printf("Error with name alloc\n"), (*error)++, 0);
		if (!make_heredoc_next(name))
		{
			printf("Error while using open in heredoc management\n");
			(*error)++;
			return (0);
		}
		i++;
		free(name);
	}
	return (1);
}
