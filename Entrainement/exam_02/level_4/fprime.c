#include <stdio.h>
#include <stdlib.h>

void    fprime(int nbr)
{
    int i;

    i = 1;
    if (nbr == 1)
        printf("1");
    while (++i <= nbr)
    {
        if (nbr % i == 0)
        {
            printf("%d", i);
            if (i == nbr)
                break ;
            printf("*");
            nbr /= i;
            i = 1;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        fprime(atoi(argv[1]));
    printf("\n");
    return (0);
}