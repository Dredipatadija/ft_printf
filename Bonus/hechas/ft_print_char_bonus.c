/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:42:41 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/15 14:50:59 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_leftaligned_char(t_format *fmt, char c, int len, char *str)
{
	if (fmt->leftaligned != 0)
	{
		while (len > 0)
			str[--len] = ' ';
		str[0] = c;
	}
	else
	{
		str[--len] = c;
		while (len > -1)
			str[--len] = ' ';
	}
	return (ft_putstr(str));
}

int	ft_print_char_bonus(char c, t_format *fmt)
{
	int		len;
	char	*str;
	int		printed;

	len = fmt->width;
	str = NULL;
	if (fmt->width < 1)
		return (ft_putchar(c));
	else
	{
		str = malloc(sizeof(char) * len + 1);
		if (!str)
			return (-1);
		str[len] = 0;
		printed = ft_leftaligned_char(fmt, c, len, str);
		free(str);
	}
	return (printed);
}
