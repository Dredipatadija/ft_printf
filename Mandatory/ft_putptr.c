/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:17:21 by arenilla          #+#    #+#             */
/*   Updated: 2024/03/28 19:40:44 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	static int		i;

	p = (unsigned long)ptr;
	i = i + write(1, "0x", 2);
	i = i + ft_puthex(p, 'x');
	return (i);
}

/*int	main(void)
{
	int	i;
	void	*pointer;

//	pointer = (void *)malloc(1);
	i = ft_putptr(pointer);
	write (1, "\n", 1);
	printf("%d", i);
	return (0);
}*/
