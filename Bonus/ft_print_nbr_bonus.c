/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:25:56 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/28 19:38:22 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

char	*ft_positnum(char *str, t_format *fmt)
{
	char	*strprecis;
	char	*padprecis;
	char	*finalstr;

	padprecis = NULL;
	strprecis = NULL;
	finalstr = ft_pluspa(str, fmt, strprecis, padprecis);
	free(str);
	if (padprecis)
		free(padprecis);
	if (strprecis)
		free(strprecis);
	return (finalstr);
}

int	ft_suprawidth(t_format *fmt, char *str)
{
	int	printedstr;
	int	pflag;

	pflag = 0;
	printedstr = 0;
	if (fmt->width <= ft_strlen(str))
	{
		printedstr = ft_putstr(str);
		if (printedstr == -1)
			return (-1);
	}
	else if (fmt->width > ft_strlen(str))
		pflag = ft_widthmajor_n(fmt, printedstr, str);
	return (pflag + printedstr);
}

static char	*ft_prepare_str(int n, t_format *fmt, int *printed)
{
	char	*str;

	str = NULL;
	if ((fmt->plus != 0 || fmt->space != 0) && n > 0)
		str = ft_positnum(ft_itoa(n), fmt);
	else if (n < 0)
	{
		str = ft_itoa(-n);
		*printed = ft_putchar('-');
		fmt->width = fmt->width - 1;
	}
	else
		str = ft_itoa(n);
	return (str);
}

int	ft_print_nbr_bonus(int n, t_format *fmt)
{
	char	*str;
	int		printed;
	char	*padprecis;
	char	*strprecis;

	strprecis = NULL;
	padprecis = NULL;
	printed = 0;
	str = ft_prepare_str(n, fmt, &printed);
	if (fmt->point == 1 && fmt->precision > ft_strlen(str))
	{
		fmt->zerofilled = 0;
		padprecis = ft_padprecis_bonus('0', (fmt->precision - ft_strlen(str)));
		strprecis = ft_strjoin(padprecis, str);
		printed = printed + ft_suprawidth(fmt, strprecis);
		free(str);
		free(padprecis);
		free(strprecis);
		return (printed);
	}
	printed = printed + ft_suprawidth(fmt, str);
	free(str);
	return (printed);
}
