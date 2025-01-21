/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:56:36 by terijo            #+#    #+#             */
/*   Updated: 2024/12/27 15:38:10 by terijo           ###   ########.fr       */
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
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (i < wc)
	{
		tab[i] = ft_word(s, &index, c);
		if (tab[i] == NULL)
			return (malloc_error(tab));
		i++;
	}
	tab[i] = 0;
	return (tab);
}
// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char **argv)
// {
//     char    ***tab;
//     int     i;
//     int     j;

//     if (argc < 2)
//     {
//         printf("Usage: ./a.out <command1> <command2> ...\n");
//         return (1);
//     }

//     tab = malloc(sizeof(char **) * (argc - 1));
//     if (!tab)
//     {
//         perror("malloc");
//         return (1);
//     }

//     i = 0;
//     while (i < argc - 1)
//     {
//         j = 0; // Réinitialiser j pour chaque commande
//         tab[i] = ft_split(argv[i + 1], ' '); // Décale argv de 1 (argv[0] est ./a.out)
//         if (!tab[i])
//         {
//             printf("Erreur : ft_split a retourné NULL.\n");
//             return (1);
//         }
//         while (tab[i][j])
//         {
//             printf("tab[%d][%d] = %s\n", i, j, tab[i][j]);
//             j++;
//         }
//         i++;
//     }
//     // Libérer la mémoire
//     for (int i = 0; i < argc - 1; i++)
//     {
//         for (int j = 0; tab[i][j]; j++)
//             free(tab[i][j]);
//         free(tab[i]);
//     }
//     free(tab);

//     return (0);
// }
// fini !
