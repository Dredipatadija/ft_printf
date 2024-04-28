/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:54:58 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/28 16:12:41 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

int	ft_widthmajor_h(t_format *fmt, long long pstr, char *s)
{
	long long	printedf;

	printedf = 0;
	if (fmt->leftaligned == 1)
	{
		pstr = ft_putstr(s);
		if (fmt->zerofilled == 0)
			printedf = ft_padwidth_bonus(' ', (fmt->width - ft_strlen(s)));
		else
			printedf = ft_padwidth_bonus('0', (fmt->width - ft_strlen(s)));
	}
	else if (fmt->leftaligned == 0)
	{
		if (fmt->zerofilled == 0)
			printedf = ft_padwidth_bonus(' ', (fmt->width - ft_strlen(s)));
		else
			printedf = ft_padwidth_bonus('0', (fmt->width - ft_strlen(s)));
		pstr = ft_putstr(s);
	}
	if (printedf == -1 || pstr == -1)
		return (ft_errorstr(s));
	return (pstr + printedf);
}

int	ft_widthmajor_n(t_format *fmt, long long pstr, char *s)
{
	long long	printedf;

	printedf = 0;
	if (fmt->leftaligned == 1)
	{
		pstr = ft_putstr(s);
		if (fmt->zerofilled == 0)
			printedf = ft_padwidth_bonus(' ', (fmt->width - ft_strlen(s)));
		else
			printedf = ft_padwidth_bonus('0', (fmt->width - ft_strlen(s)));
	}
	else if (fmt->leftaligned == 0)
	{
		if (fmt->zerofilled == 0)
			printedf = ft_padwidth_bonus(' ', (fmt->width - ft_strlen(s)));
		else
			printedf = ft_padwidth_bonus('0', (fmt->width - ft_strlen(s)));
		pstr = ft_putstr(s);
	}
	if (printedf == -1 || pstr == -1)
		return (-1);
	return (pstr + printedf);
}

void	ft_pointernegate(t_format *fmt)
{
	fmt->hash = 0;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->point = 0;
	fmt->precision = 0;
	fmt->zerofilled = 0;
}

char	*ft_conditionprecis(t_format *fmt, char *str)
{
	char	*strprecis;
	char	*s;

	s = NULL;
	strprecis = NULL;
	if (fmt->point == 1 && fmt->precision > ft_strlen(str))
	{
		strprecis = ft_padprecis_bonus('0', (fmt->precision - ft_strlen(str)));
		s = ft_strjoin(strprecis, str);
		free(strprecis);
		free(str);
	}
	else
	{
		s = ft_strdup(str);
		free(str);
	}
	return (s);
}

char	*ft_pluspa(char *str, t_format *fmt, char *strprecis, char *padprecis)
{
	char	*finalstr;

	finalstr = NULL;
	if (fmt->point == 1 && fmt->precision > ft_strlen(str))
	{
		padprecis = ft_padprecis_bonus('0', (fmt->precision - ft_strlen(str)));
		strprecis = ft_strjoin(padprecis, str);
		if (fmt->plus != 0)
			finalstr = ft_strjoin("+", strprecis);
		else
			finalstr = ft_strjoin(" ", strprecis);
	}
	else if (fmt->point == 0 || fmt->precision <= ft_strlen(str))
	{
		if (fmt->plus != 0)
			finalstr = ft_strjoin("+", str);
		else
			finalstr = ft_strjoin(" ", str);
	}
	return (finalstr);
}
