/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:17:21 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/27 20:59:20 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

int	ft_print_ptr_bonus(void *ptr, t_format *fmt)
{
	unsigned long	p;
	int				printedhex;

	p = (unsigned long)ptr;
	printedhex = ft_print_hex_bonus(p, 'p', fmt);
	if (printedhex == -1)
		return (-1);
	return (printedhex);
}
