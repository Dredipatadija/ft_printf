/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:49:35 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/20 22:33:39 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_putunbr(unsigned long n)
{
	static int		printed;
	char	num;

	printed = 0;
	if (n > 9)
		ft_putunbr(n / 10);
	num = (n % 10) + 48;
	printed = printed + write(1, &num, 1);
	return (printed);
}
