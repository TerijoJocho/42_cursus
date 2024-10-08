#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	s1[] = "lablabla";
	char	s2[] = "bonojur";
	char	*ref;

	// ref = strpbrk(s1, s2);
	ref = ft_strpbrk(s1, s2);
	printf("%s", ref);
}
