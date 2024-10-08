#include <stdio.h>
#include <string.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

int main() {
    const char str[] = "Bon jour,monde!";
    const char reject[] = " ,!";

    printf("VRAIE :La longueur du segment sans espace, virgule ou point d'exclamation est : %zu\n", strcspn(str, reject));
    printf("MOI :La longueur du segment sans espace, virgule ou point d'exclamation est : %zu\n", ft_strcspn(str, reject));

    return 0;
}