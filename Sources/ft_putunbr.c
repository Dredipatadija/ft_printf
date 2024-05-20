/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:49:35 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/21 19:19:09 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_putunbr(unsigned long n)
{
	static int	printed;
	char		num;
	int			i;

	printed = 0;
	if (n > 9)
	{
		i = ft_putunbr(n / 10);
		if (i == -1)
			return (-1);
	}
	num = (n % 10) + 48;
	i = write(1, &num, 1);
	if (i == -1)
		return (-1);
	printed = printed + i;
	return (printed);
}
