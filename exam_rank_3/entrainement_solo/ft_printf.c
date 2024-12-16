#include <stdarg.h>
#include <unistd.h>

void    ft_putstr(const char *str, int *count)
{
    if (!str)
        str = "(null)";
    while (*str)
    {
        write(1, str, 1);
        str++;
        (*count)++;
    }
}

void    ft_putnbr(int arg, int *count)
{
    int n;

    if (arg == -2147483648)
    {
        ft_putstr("-2147483648", count);
        return ;
    }
    if (arg > 9)
        ft_putnbr(arg / 10, count);
    n = arg % 10 + '0';
    write(1, &n, 1);
   (*count)++;
}

void    ft_puthex(unsigned int arg, int *count)
{
    char    hex[] = "0123456789abcdef";
    unsigned int    n;

    if (arg > 16)
        ft_puthex(arg / 16, count);
    n = arg % 16;
    write(1, &hex[n], 1);
    (*count)++;
}

int ft_printf(const char *format, ...)
{
    int count;
    va_list args;

    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if(*format == 's')
                ft_putstr(va_arg(args, char *), &count);
            else if(*format == 'd')
                ft_putnbr(va_arg(args, int), &count);
            else if(*format == 'x')
                ft_puthex(va_arg(args, unsigned int), &count);
            else
            count += write(1, format, 1);
        }
        else
            count += write(1, format, 1);
        format++;
    }
    va_end(args);
    return (count);
}

#include <stdio.h>

int main(void)
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