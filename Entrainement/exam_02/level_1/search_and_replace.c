#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str)
    {
        write(1, &(*str), 1);
        str++;
    }
}

void    search_and_replace(char *str, char *search, char *replace)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == *search)
            str[i] = *replace;
        i++;
    }
    ft_putstr(str);
}

int main(int argc, char **argv)
{
    if (argc == 4)
        search_and_replace(argv[1], argv[2], argv[3]);
    write(1, "\n", 1);
    return (0);
}