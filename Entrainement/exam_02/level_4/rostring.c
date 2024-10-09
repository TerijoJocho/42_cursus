#include <unistd.h>
#include <stdlib.h>

void    rostring(char *str)
{
    char *first_word_start;
    char *first_word_end;
    int i;

    i = 0;
    while (str[i]==' ' || str[i]=='\t')
        i++;
    first_word_start = &str[i];
    while (str[i] && str[i]!=' ' && str[i]!='\t')
        i++;
    first_word_end = &str[i];
    while (str[i]==' ' || str[i]=='\t')
        i++;
    if (str[i])
    {
        while (str[i])
        {
            if (str[i]==' ' || str[i]=='\t')
            {
                while (str[i]==' ' || str[i]=='\t')
                    i++;
                if (str[i])
                    write(1, " ", 1);
            }
            else
            {
                write(1, &str[i], 1);
                i++;
            }
        }
        write(1, " ", 1);
    }
    while (first_word_start < first_word_end)
    {
        write(1, first_word_start, 1);
        first_word_start++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rostring(argv[1]);
    write(1, "\n", 1);
    return (0);
}
