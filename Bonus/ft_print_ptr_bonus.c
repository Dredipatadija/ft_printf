/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:17:21 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/21 20:00:21 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"

char	*ft_print_ptr_bonus(void *ptr, t_format *fmt)
{
	unsigned long	p;
	int				printedhex;
	int				printedpre;

	p = (unsigned long)ptr;
	printedpre = ft_putstr("0x");
	printedhex = ft_print_hex_bonus(p, 'x', fmt);
	if (printedpre == -1 || printedhex == -1)
		return (-1);
	return (printedhex + printedpre);
}
