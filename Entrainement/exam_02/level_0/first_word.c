#include <unistd.h>

void    first_word(char *str)
{
    int i;

    i = 0;
    while (str[i] == 32 || str[i] == 9)
        i++;
    while (str[i] != '\0' && str[i] != 32 && str[i] != 9)
    {
       write(1, &str[i], 1);
       i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        first_word(argv[1]);
    return (0);
}