#include <unistd.h>
#include <stdlib.h>

/*static int str_len(char *s)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            len++;
        i++;
    }
    return (i + len);
}

void    camel_to_snake(char *str)
{
    int i;
    int j;
    char    *res;

    i = 0;
    j = 0;
    res = malloc(sizeof(char) * (str_len(str)+ 1));
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
            write(1, "_", 1);
            j++;
        }
        res[j] = str[i]; 
        write(1, &res[j], 1); 
        i++;
        j++;
    }
}*/

void    camel_to_snake(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
            write(1, "_", 1);
        }
        write(1, &str[i], 1); 
       i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        camel_to_snake(argv[1]);
    write(1, "\n", 1);
    return (0);
}