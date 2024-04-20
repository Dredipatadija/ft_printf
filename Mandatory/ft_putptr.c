/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:17:21 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/20 21:28:32 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				i;
	int				j;

	p = (unsigned long)ptr;
	i = write(1, "0x", 2);
	j = ft_puthex(p, 'x');
	if (i == -1 || j == -1)
		return (-1);
	return (i + j);
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
