/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:17:21 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/15 14:44:33 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_ptr_bonus(void *ptr, t_format *fmt)
{
	unsigned long	p;
	char			*strhex;
	char			*str;
	char			*spacestr;
	int				i;

	i = 0;
	spacestr = NULL;
	p = (unsigned long)ptr;
	strhex = ft_print_hex_bonus(p, 'x', fmt);
	while (strhex[i] == ' ')
		spacestr[i++] = ' ';
	str = ft_strjoin("0x", (char const *)&strhex[i]);
	str = ft_strjoin((char const *)spacestr, (char const *)str);
	free (strhex);
	return (str);
}
