#include <unistd.h>

void    iter(char *s1, char *s2)
{
    int i;
    int j;
    char    dico[256] = {0};

    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j] && dico[s1[i]] == 0)
            {
                write(1, &s1[i], 1);
                dico[s1[i]] = 1;
            }
            j++;
        }
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        iter(argv[1], argv[2]);
    else 
        write(1, "\n", 1);
    return (0);
}