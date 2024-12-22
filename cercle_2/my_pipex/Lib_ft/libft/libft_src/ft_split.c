/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:56:36 by terijo            #+#    #+#             */
/*   Updated: 2024/12/22 12:03:43 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

static char	**malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	ft_word_count(char const *s1, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			i++;
		else
		{
			count++;
			while (s1[i] && s1[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_word(const char *str, int *index, char c)
{
	int		i;
	size_t	word_len;
	char	*cpy;

	word_len = 0;
	while (str[*index] && str[*index] == c)
		(*index)++;
	i = *index;
	while (str[i] && str[i] != c)
	{
		word_len++;
		i++;
	}
	cpy = (char *)malloc(sizeof(char) * (word_len + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (str[*index] && str[*index] != c)
		cpy[i++] = str[(*index)++];
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wc;
	int		index;
	char	**tab;

	wc = ft_word_count(s, c);
	//verif
	printf("ft_split: String to split = '%s', word count = %d\n", s, wc);
	//verif
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (i < wc)
	{
		tab[i] = ft_word(s, &index, c);
		//verif
		printf("ft_split: Allocated word[%d] = '%s'\n", i, tab[i]);
		//verif
		if (tab[i] == NULL)
			return (malloc_error(tab));
		i++;
	}
	tab[i] = 0;
	//verif
	for (int i = 0; tab[i] != NULL; i++)
    	printf("result[%d]: %s\n", i, tab[i]);
	//verif
	return (tab);
}
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	char **result = ft_split("grep a1 ca ca caca", ' ');

// 	if (!result)
// 	{
// 		printf("Erreur : ft_split a retourné NULL.\n");
// 		return (1);
// 	}

// 	for (int i = 0; result[i]; i++)
// 		printf("arg[%d]: %s\n", i, result[i]);

// 	// Libérer la mémoire
// 	for (int i = 0; result[i]; i++)
// 		free(result[i]);
// 	free(result);

// 	return (0);
// }
// fini !
