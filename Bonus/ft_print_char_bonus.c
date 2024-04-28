/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:42:41 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/28 13:38:23 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

static int	ft_withleftaligned(t_format *fmt, char c, int printed)
{
	int	i;
	int	j;

	j = 0;
	i = ft_putchar(c);
	if (i == -1)
		return (-1);
	if (c == '%' && fmt->zerofilled == 1)
	{
		j = ft_padwidth_bonus('0', (fmt->width - 1));
		if (j == -1)
			return (-1);
	}
	else if (c != '%' || fmt->zerofilled == 0)
	{
		j = ft_padwidth_bonus(' ', (fmt->width - 1));
		if (j == -1)
			return (-1);
	}
	printed = i + j;
	return (printed);
}

static int	ft_noleftaligned(t_format *fmt, char c, int printed)
{
	int	i;
	int	j;

	j = 0;
	if (c == '%' && fmt->zerofilled == 1)
	{
		j = ft_padwidth_bonus('0', (fmt->width - 1));
		if (j == -1)
			return (-1);
	}
	else if (c != '%' || fmt->zerofilled == 0)
	{
		j = ft_padwidth_bonus(' ', (fmt->width - 1));
		if (j == -1)
			return (-1);
	}
	i = ft_putchar(c);
	if (i == -1)
		return (-1);
	printed = i + j;
	return (printed);
}

static int	ft_leftaligned_char(t_format *fmt, char c)
{
	int	printed;

	printed = 0;
	if (fmt->leftaligned != 0)
		printed = ft_withleftaligned(fmt, c, printed);
	else
		printed = ft_noleftaligned(fmt, c, printed);
	return (printed);
}

int	ft_print_char_bonus(char c, t_format *fmt)
{
	int		printed;

	if (fmt->width < 2)
		return (ft_putchar(c));
	else
		printed = ft_leftaligned_char(fmt, c);
	return (printed);
}
