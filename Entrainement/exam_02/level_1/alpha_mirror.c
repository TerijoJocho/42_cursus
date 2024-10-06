#include <unistd.h>

void    alpha_mirror(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = 219 - str[i]; //pos_z = 219 - pos_a
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = 155 - str[i];
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        alpha_mirror(argv[1]);
    write(1, "\n", 1);
    return (0);
}