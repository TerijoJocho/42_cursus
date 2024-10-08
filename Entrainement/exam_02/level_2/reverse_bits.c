unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

#include <stdio.h>

int	main(void)
{
	char	c = '1';
	unsigned char r;

	r = reverse_bits(c);
	printf("%c", r);
	return (0);
}



