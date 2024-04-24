/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:57:37 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/23 20:48:50 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"
//#include <stdio.h>

static void	ft_initflags_bonus(t_format *fmt)
{
	ft_memset(fmt, 0, sizeof(t_flags));
}

int	ft_printf_bonus(const char *format, ...)
{i
	va_list		args;
	t_format	*fmt;
	int			total;
	int			count;

	total = 0;
	fmt = (t_format *)ft_calloc(1, sizeof(t_format));
	if (!fmt)
		return (-1);
	ft_initflags_bonus(fmt);
	va_start(args, format);
	if (format)
	{
		while (*format != '\0')
		{
			if (*format == '%' && *(++format) != '\0')
			{
				count = ft_check_bonus(format, fmt, args);
				ft_initflags_bonus(fmt);
			}
			else if (*format != '%')
				count = ft_putchar(*format);
			if (count == -1)
				return (-1);
			++format;
			total = total + count;
		}
	}
	va_end(args);
	free(fmt);
	return (total);
}

/*int	main(void)
{
	int c;
	
	c = '0';
	printf("%-1c\n", c);
	ft_printf("%-1c\n", c);
	return (0);
}*/
