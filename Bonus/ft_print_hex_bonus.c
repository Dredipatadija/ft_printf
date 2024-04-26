/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:40:59 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/26 08:56:15 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

static size_t	ft_hexlen(unsigned long n)
{
	size_t			len;
	unsigned long	num;

	num = n;
	len = 1;
	while (num > 15)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static char	*ft_fillhex(unsigned long n, char ch, size_t len, char *str)
{
	while (n > 0)
	{
		if (n > 15)
		{
			if (ch == 'x')
				str[len] = "0123456789abcdef"[n % 16];
			if (ch == 'X')
				str[len] = "0123456789ABCDEF"[n % 16];
			n = n / 16;
			len--;
		}
		else
		{
			if (ch == 'x')
				str[len] = "0123456789abcdef"[n % 16];
			if (ch == 'X')
				str[len] = "0123456789ABCDEF"[n % 16];
			break ;
		}
	}
	return (str);
}

static char	*ft_itohex(int len, unsigned long n, char ch, t_format *fmt)
{
	char	*str;
	char	*strfin;

	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = 0;
	if (n == 0)
		str[len] = '0';
	else
	{
		str = ft_fillhex(n, ch, len, str);
		if (fmt->hash == 0)
			return (str);
		else if (fmt->hash != 0)
		{
			if (ch == 'x')
				strfin = ft_strjoin("0x", str);
			else if (ch == 'X')
				strfin = ft_strjoin("0X", str);
		}
	}
	free(str);
	return (strfin);
}

int	ft_print_hex_bonus(unsigned long n, char ch, t_format *fmt)
{
	char	*str;
	int		printedflag;
	int		printedstr;

	printedflag = 0;
	printedstr = 0;
	str = ft_itohex(ft_hexlen(n), n, ch, fmt);
	if (fmt->width <= ft_strlen(str))
		printedstr = ft_putstr(str);
	else if (fmt->width > ft_strlen(str))
	{
		printedflag = ft_padwidth_bonus(' ', (fmt->width - ft_strlen(str)));
		printedstr = ft_putstr(str);
		if (printedflag == -1 || printedstr == -1)
			return (ft_errorstr(str));
	}
	free(str);
	return (printedstr + printedflag);
}
