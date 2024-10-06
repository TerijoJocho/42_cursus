#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void ft_swap(int *a, int *b);

int main(void)
{
    int x = 42;
    int y = 84;

    printf("Avant l'échange: x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("Après l'échange: x = %d, y = %d\n", x, y);

    return 0;
}