/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:25:56 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/20 22:47:39 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_putnbr(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(n);
	i = ft_putstr(str);
	free(str);
	return (i);
}
