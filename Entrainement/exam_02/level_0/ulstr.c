#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str)
    {
        write(1, &(*str), 1);
        str++;
    }
}

void   ultstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32; 
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;     
        i++;
    }
    ft_putstr(str);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    ultstr(argv[1]);
    write(1, "\n", 1);
    return (0);
}