/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:00:33 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/21 20:11:28 by arenilla         ###   ########.fr       */
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

static char	*ft_uitoa(size_t len, unsigned int n)
{
	char	*str;

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
	return (str);
}

int	ft_print_unbr_bonus(unsigned int n, t_format *fmt)
{
	char	*str;
	int		printedflag;
	int		printedstr;

	printedflag = 0;
	printedstr = 0;
	str = ft_uitoa(ft_numlen(n), n);
	if (fmt->width <= ft_strlen(str))
		printedstr = ft_putstr(str);
	else if (fmt->width > ft_strlen(str))
	{
		if (fmt->zerofilled != 0)
			printedflag = ft_padwidth_bonus('0', (fmt->width - ft_strlen(str)));
		else
			printedflag = ft_padwidth_bonus(' ', (fmt->width - ft_strlen(str)));
		if (printedflag == -1)
			return (ft_errorstr(str));
		printedstr = ft_putstr(str);
		if (printedstr == -1)
			return (ft_errorstr(str));
	}
	free(str);
	return (printedstr + printedflag);
}
