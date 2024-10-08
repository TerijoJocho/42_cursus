#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i;
    int len;
    char    *res;

    i = 0;
    len = 0;
    while(src[len])
        len++;
    res = malloc(sizeof(char)*len+1);
    if (res == NULL)
        return (NULL);
    while(src[i])
    {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

int main(void)
{
    char    str[] = "booh";
    char    *res;
    char    *res2;

    res = strdup(str);
    res2 = ft_strdup(str);
    printf("vrai : %s\n", res);
    printf("vrai : %s\n", res2);
    return (0);
}