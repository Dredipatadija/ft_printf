/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:40:59 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/20 22:48:39 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_condhex(unsigned long n, char ch, int i)
{
	char	number;

	if (n > 15)
	{
		ft_puthex((n / 16), ch);
		ft_puthex((n % 16), ch);
	}
	if (n < 10)
	{
		number = n + 48;
		i = i + write(1, &number, 1);
	}
	if (n > 9 && n < 16)
	{
		n = n - 10;
		if (ch == 'x')
			number = n + 97;
		if (ch == 'X')
			number = n + 65;
		i = i + write(1, &number, 1);
	}
	return (i);
}

int	ft_puthex(unsigned long n, char ch)
{
	static int	i;

	i = 0;
	if (n == 0)
		i = i + write(1, "0", 1);
	else
		i = ft_condhex(n, ch, i);
	return (i);
}

/*int	main(void)
{
	int	i;
	int	n;

	n = 2147483647;
	i = ft_puthex(n, 'x');
	printf("\n%d", i);
	return (0);
}*/
