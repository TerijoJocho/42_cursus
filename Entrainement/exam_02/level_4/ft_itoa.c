#include <stdlib.h>
#include <stdio.h>

char    *ft_itoa(int nbr)
{
    int n;
    int len;
    char *res;

    if (nbr == -2147483648)
        return("-2147483648\0");
    n = nbr;
    len = 0;
    if (nbr <= 0)
        len++;
    while (n)
    {
        n /= 10;
        len++;
    }
    res = malloc(sizeof(char) * (len + 1));
    if (res == NULL)
        return (NULL);
    res[len] = '\0';
    if (nbr == 0)
    {
        res[0] = '0';
        return (res);
    }
    if (nbr < 0)
    {
        res[0] = '-';
        nbr *= -1;
    }
    while (nbr)
    {
        res[--len] = (nbr % 10) + '0'; 
        nbr /= 10;
    }
    return (res);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *res = ft_itoa(atoi(argv[1]));

        printf("moi : %s\n", res);
    }
    return (0);
}
