#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<stdarg.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	char	*c = "bonjour";
	int		i = 46354;
	unsigned int	k = 10;

	ft_printf("char: %s\n", c);
	ft_printf("int: %d\n", i);
	ft_printf("hexa: %x\n", k);
	printf("real char: %s\n", c);
	printf("real int: %d\n", i);
	printf("real hexa: %x\n", k);
	return (0);
}
