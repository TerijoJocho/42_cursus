

#include "../includes/cube3d.h"

int    ft_is_cub(char *argv)
{
    char    *str;

    str = strrchr(argv, '.');
    if (strncmp(str, ".cub", 5))
        return (printf("error: not a .cub file\n"), 1);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (printf("error: argument missing\n"), 1);
    else if (argc > 2)
        return (printf("error: too much arguments\n\n"), 1);
    ft_is_cub(argv[1]);
    ft_get_file(argv[1]);
    return (0);
}