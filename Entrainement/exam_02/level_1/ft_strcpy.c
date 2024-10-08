#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_strcpy(char *dst, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

int main(void)
{
    char    *dst;
    char    *src = "bonjour";

    dst = malloc(sizeof(char)*8);
    ft_strcpy(dst, src);
    printf("%s", dst);
}