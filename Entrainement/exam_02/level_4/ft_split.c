#include <stdlib.h>
#include <stdio.h>

char    *ft_strncpy(char *dest, char *src, int n)
{
    int i;

    i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int count_word(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        else
        {
            if (str[i+1] == ' ' || str[i+1] == '\t' || str[i+1] == '\n' || str[i+1] == '\0')
                count++;
            i++;
        }
    }
    return (count);
}

char    **ft_split(char *str)
{
    int     words;
    int     i;
    int     j;
    int     k;
    char    **tab;

    words = count_word(str);
    tab = malloc(sizeof(char *) * (words+1));
    if (tab == NULL)
        return (NULL);
    i = 0;
    k = 0;
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        j = i;
        while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
        if (i > j)
        {
            tab[k] = malloc(sizeof(char) * ((i - j) + 1));
            ft_strncpy(tab[k], &str[j], i-j);
            k++;
        }
    }
    tab[k] = NULL;
    return (tab);
}

int	main(void)
{
	int     i;
	char    *str = "";
	char    **tab;

	i = 0;
	printf("str :%s.\n", str);
	tab = ft_split(str);

	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}