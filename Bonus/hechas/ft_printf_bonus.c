/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:57:37 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/20 18:59:09 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	va_list		args;
	t_format	*fmt;
	int			total;

	i = 0;
	va_start(args, format);
	fmt = ft_calloc(1, sizeof(t_format *));
	if (!fmt)
		return (-1);
	ft_init_flags(fmt);
	fmt->bprinted = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *(++format) != '\0')
			fmt->bprinted = (fmt->bprinted) + ft_check_bonus(format, fmt, args);
		else if (*format != '%')
		{
			fmt->bprinted = fmt->bprinted + ft_putchar(format[i]);
			format++;
		}
	}
	va_end(args);
	total = fmt->bprinted;
	free(fmt);
	return (total);
}
