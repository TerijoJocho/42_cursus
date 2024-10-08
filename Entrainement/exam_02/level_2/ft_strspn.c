#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	while(*str)
	{
		if(*str == c)
			return ((char *)str);
		str++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((ft_strchr(accept, s[i])) == 0)
			break;
		i++;
	}
	return (i);
}

int main() {
    const char *str = "ab1234";
    const char *accept = "acd";

    printf("VRAIE :La longueur du segment avec espace, virgule ou point d'exclamation est : %zu\n", strspn(str, accept));
    printf("MOI :La longueur du segment avec espace, virgule ou point d'exclamation est : %zu\n", ft_strspn(str, accept));

    return 0;
}
