/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:25:56 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/23 19:37:42 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

static char	*ft_positnum(char *str, t_format *fmt)
{
	char	*positstr;

	positstr = NULL;
	if (fmt->plus != 0)
		positstr = ft_strjoin("+", (char const *)str);
	else if (fmt->space != 0)
		positstr = ft_strjoin(" ", (char const *)str);
	return (positstr);
}

static int	ft_suprawidth(t_format *fmt, char *str)
{
	int	printedstr;
	int	printedflag;

	printedflag = 0;
	printedstr = 0;
	if (fmt->width <= ft_strlen(str))
	{
		printedstr = ft_putstr(str);
		if (printedstr == -1)
			return (-1);
	}
	else if (fmt->width > ft_strlen(str))
	{
		if (fmt->zerofilled != 0)
			printedflag = ft_padwidth_bonus('0', (fmt->width - ft_strlen(str)));
		else
			printedflag = ft_padwidth_bonus(' ', (fmt->width - ft_strlen(str)));
		if (printedflag == -1)
			return (-1);
		printedstr = ft_putstr(str);
		if (printedstr == -1)
			return (-1);
	}
	return (printedflag + printedstr);
}

int	ft_print_nbr_bonus(int n, t_format *fmt)
{
	char	*str;
	int		printed;

	printed = 0;
	if ((fmt->plus != 0 || fmt->space != 0) && n > 0)
		str = ft_positnum(ft_itoa(n), fmt);
	else
		str = ft_itoa(n);
	printed = ft_suprawidth(fmt, str);
	free(str);
	return (printed);
}
