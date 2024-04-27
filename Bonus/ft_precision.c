/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:02:28 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/27 15:10:58 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

const char	*ft_precision(t_format *fmt, const char *format)
{
	fmt->precision = ft_atoi(format);
	while (ft_strchr("0123456789", *format))
		++format;
	return (format);
}
