char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	char	temp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	len--;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	s[]="0123456 78 9 ";

	printf("origin: %s\n",s);
	printf("after:%s\n", ft_strrev(s));

	return (0);
}
