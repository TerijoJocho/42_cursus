int ft_atoi(const char *str)
{
    int i;
    int sign;
    int res; 

    i = 0;
    res = 0;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
       if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + str[i] - '0' ;
        i++;
    }
    return (sign * res);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        printf("mine %d\n",ft_atoi(argv[1]));
        printf("not mine %d",atoi(argv[1]));
    }
    return (0);
}