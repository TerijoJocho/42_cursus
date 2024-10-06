#include <unistd.h>

void    last_word(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    i--;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))   
            i--;
    while (i >= 0 && s[i] != ' ' && s[i] != '\t')   
            i--;
    if (s[i] == ' ' || s[i] == '\t')
        i++;
    while (s[i] != '\0' && (s[i] != ' ' || s[i] != '\t'))
    {
        write(1, &s[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        last_word(argv[1]);
    else 
        write(1, "\n", 1);
    return (0);
}