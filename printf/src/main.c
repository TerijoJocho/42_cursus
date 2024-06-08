#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	main(void)
{
	char *p = "yjtdtcg";
	char c = 'd';
	int x = 10;
	unsigned int j = 123456;
	unsigned int h = 13654651;

	printf("vrai p: %p\n", &p);
	ft_printf("moi p: %p\n", &p);
	printf("vrai s: %s\n", p);
	ft_printf("moi s: %s\n", p);
	printf("vrai i: %i\n", x);
	ft_printf("moi i: %i\n", x);
	printf("vrai d: %d\n", x);
	ft_printf("moi d: %d\n", x);
	printf("vrai c: %c\n", c);
	ft_printf("moi c: %c\n", c);
	printf("vrai u: %u\n", j);
	ft_printf("moi u: %u\n", j);
	printf("vrai %%\n");
	ft_printf("moi %%\n");
	printf("vrai x: %X\n", h);
	ft_printf("moi x: %X\n", h);
	printf("vrai x: %x\n", h);
	ft_printf("moi x: %x", h);
	return (0);
}