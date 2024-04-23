/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:42:41 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/23 20:47:27 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

static int	ft_leftaligned_char(t_format *fmt, char c)
{
	int	printed;
	int	i;
	int	j;
	int space;

	j = 0;
	i = 0;
	space = 0;
	printed = 0;
	if (fmt->leftaligned != 0)
	{
		i = ft_putchar(c);
		if (i == -1)
			return (-1);
		while (j < ((int)fmt->width - 1))
		{
			j = ft_putchar(' ');
			if (j == -1)
				return (-1);
			space++;
		}
		printed = i + space;
	}
	else
	{
		while (j < ((int)fmt->width - 1))
		{
			j = ft_putchar(' ');
			if (j == -1)
				return (-1);
			space++;
		}
		i = ft_putchar(c);
		if (i == -1)
			return (-1);
		printed = i + space;
	}
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
