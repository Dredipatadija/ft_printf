#include "ft_printf.h"
#include "libft.h"

static void	ft_initflags_bonus(t_format *fmt)
{
	fmt->width = 0;
	fmt->zerofilled = 0;
	fmt->leftaligned = 0;
	fmt->hash = 0;
	fmt->plus = 0;
	fmt->space = 0;
}

int	ft_printf_bonus(const char *format, ...)
{
	va_list	args;
	t_format	*fmt;
	int		total;

	i = 0;
	va_start(args, format);
	fmt = ft_calloc(1, sizeof(t_format *));
	if (!fmt)
		return (-1);
	ft_init_flags(fmt);
	fmt->bytesprinted = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *(++format) != '\0')
			fmt->bytesprinted = (fmt->bytesprinted) + ft_check_bonus(format, fmt, args);
		else if (*format != '%')
		{
			fmt->bytesprinted = fmt->bytesprinted + ft_putchar(format[i]);
			format++;
		}
	}
	va_end(args);
	total = fmt->bytesprinted;
	free(fmt);
	return (total);
}
