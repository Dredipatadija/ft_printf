/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:45:16 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/28 19:29:56 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

char	*ft_unbrconditions(size_t l, char *str, unsigned int n, t_format *fmt)
{
	char	*finalstr;
	size_t	i;
	char	*strprecis;

	strprecis = NULL;
	i = l;
	finalstr = NULL;
	str[l--] = 0;
	if (n == 0)
	{
		str[l] = '0';
		return (str);
	}
	str = ft_fillstr(n, l, str);
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

int	ft_unbrlefta(t_format *fmt, int printedstr, char *str, int pflag)
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
	return (printedstr + pflag);
}
