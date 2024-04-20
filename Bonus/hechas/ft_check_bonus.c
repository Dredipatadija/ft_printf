/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:55:57 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/15 14:50:48 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bonusflags(const char *format, t_format *fmt)
{
	char	*flags;

	flags = "0-#+ ";
	while (ft_strchr(flags, *format) && *format != '\0')
	{
		if (*format == '0')
			fmt->zerofilled = 1;
		else if (*format == '-')
			fmt->leftaligned = 1;
		else if (*format == '#')
			fmt->hash = 1;
		else if (*format == '+')
			fmt->plus = 1;
		else if (*format == ' ')
			fmt->space = 1;
		else
			return ;
		format++;
	}
}

static void	ft_width(const char *format, t_format *fmt, va_list args)
{
	if (*format == '*')
	{
		fmt->width = va_arg(args, int);
		format++;
		return ;
	}
	else
	{
		fmt->width = ft_atoi(format);
		format++;
	}
}

static int	ft_spec_str(char ch, va_list args, t_format *fmt)
{
	if (ch == 'c')
		return (ft_print_char_bonus(va_arg(args, int), fmt));
	else if (ch == 's')
		return (ft_print_str_bonus(va_arg(args, char *), fmt));
	else if (ch == 'd' || ch == 'i')
		return (ft_print_nbr_bonus(va_arg(args, int), fmt));
	else if (ch == 'u')
		return (ft_print_unbr_bonus(va_arg(args, unsigned int), fmt));
	else if (ch == '%')
		return (ft_print_char_bonus('%', fmt));
	else if (ch == 'x')
		return (ft_print_hex_bonus(va_arg(args, unsigned int), 'x', fmt));
	else if (ch == 'X')
		return (ft_print_hex_bonus(va_arg(args, unsigned int), 'X', fmt));
	else if (ch == 'p')
		return (ft_print_ptr_bonus(va_arg(args, void *), fmt));
	return (-1);
}

int	ft_check_bonus(const char *format, t_format *fmt, va_list args)
{
	int	printed;

	printed = 0;
	while (*format != '\0')
	{
		if (ft_strchr("0-#+ ", *format))
			ft_bonusflags(format, fmt);
		else if (ft_strchr("*123456789", *format))
			ft_width(format, fmt, args);
		else if (ft_strchr("cspdiuxX", *format))
			printed = ft_spec_str(*format, args, fmt);
		else
			return (-1);
	}
	return (printed);
}
