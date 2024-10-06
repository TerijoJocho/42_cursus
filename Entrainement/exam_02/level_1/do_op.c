#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    do_op(char *str_x, char *op, char *str_y)
{
    int x;
    int y;

    x = atoi(str_x);
    y = atoi(str_y);
    if (*op == '+')
        printf("%d", (x+y));
    else if (*op == '-')
        printf("%d", (x-y));
    else if (*op == '*')
        printf("%d", (x*y));
    else if (*op == '/')
        printf("%d", (x/y));
    else if (*op == '%')
        printf("%d", (x%y));
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc == 4)
        do_op(argv[1], argv[2], argv[3]);
    else 
        printf("\n");
    return (0);
}