/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:25:56 by arenilla          #+#    #+#             */
/*   Updated: 2024/03/28 16:30:31 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	static int	i;
	char		number;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (n < 0)
		{
			i = write(1, "-", 1);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10);
		number = (n % 10) + 48;
		i = i + write(1, &number, 1);
	}
	return (i);
}
