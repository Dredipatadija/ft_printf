/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:00:33 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/28 13:44:30 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

static size_t	ft_numlen(unsigned long n)
{
	size_t			len;
	unsigned long	num;

	num = n;
	len = 1;
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char	*ft_fillstr(unsigned int n, size_t len, char *str)
{
	while (n > 0)
	{
		if (n > 9)
		{
			str[len] = (n % 10) + 48;
			n = n / 10;
			len--;
		}
		else
		{
			str[len] = n + 48;
			break ;
		}
	}
	return (str);
}

static char	*ft_uitoa(size_t len, unsigned int n, t_format *fmt)
{
	char	*str;
	char	*finalstr;
	char	*strprecis;
	size_t	i;

	finalstr = NULL;
	strprecis = NULL;
	i = len;
	if (fmt->point == 1)
		fmt->zerofilled = 0;
	if (fmt->point == 1 && fmt->precision > len)
		str = malloc(sizeof(char) * fmt->precision);
	else
		str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = 0;
	if (n == 0)
	{
		str[len] = '0';
		return (str);
	}
	str = ft_fillstr(n, len, str);
	if (fmt->precision <= i)
		return (str);
	else
	{
		strprecis = ft_padprecis_bonus('0', fmt->precision - i);
		finalstr = ft_strjoin(strprecis, str);
		free(strprecis);
		free(str);
	}
	return (finalstr);
}

int	ft_print_unbr_bonus(unsigned int n, t_format *fmt)
{
	char	*str;
	int		pflag;
	int		printedstr;

	pflag = 0;
	printedstr = 0;
	str = ft_uitoa(ft_numlen(n), n, fmt);
	if (fmt->width <= ft_strlen(str))
		printedstr = ft_putstr(str);
	else if (fmt->width > ft_strlen(str))
	{
		if (fmt->leftaligned == 1)
		{
			printedstr = ft_putstr(str);
			if (fmt->zerofilled != 0)
				pflag = ft_padwidth_bonus('0', (fmt->width - ft_strlen(str)));
			else
				pflag = ft_padwidth_bonus(' ', (fmt->width - ft_strlen(str)));
		}
		else
		{
			if (fmt->zerofilled != 0)
				pflag = ft_padwidth_bonus('0', (fmt->width - ft_strlen(str)));
			else
				pflag = ft_padwidth_bonus(' ', (fmt->width - ft_strlen(str)));
			printedstr = ft_putstr(str);
		}
		if (pflag == -1)
			return (ft_errorstr(str));
		if (printedstr == -1)
			return (ft_errorstr(str));
	}
	free(str);
	return (printedstr + pflag);
}
