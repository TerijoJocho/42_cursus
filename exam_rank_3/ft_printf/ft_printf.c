#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<stdarg.h>

void	ft_putstr(const char *arg, int *count)
{
	if (!arg)
		arg = "(null)";
	while (*arg)
	{
		write(1, arg++, 1);
		(*count)++;
	}
}

void	ft_putnbr(int nbr, int *count)
{
	char	n;

	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, count);
	n = nbr % 10 + '0';
	write(1, &n, 1);
	(*count)++;
}

void	ft_puthexa(unsigned int nbr, int *count)
{
	char	*hex = "0123456789abcdef";

	if (nbr >= 16)
		ft_puthexa(nbr / 16, count);
	write(1, &hex[nbr % 16], 1);
	(*count)++;
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (*format == 'd')
				ft_putnbr(va_arg(args, int), &count);
			else if (*format == 'x')
				ft_puthexa(va_arg(args, unsigned int), &count);
			else
			{
				write(1, format, 1);
				count++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
