/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:46:31 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/20 22:24:36 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		totalprint;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	totalprint = 0;
	if (format)
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%' && format[i + 1] != '\0')
			{
				i++;
				count = ft_check(format[i], args);
				if (count == -1)
					return (-1);
			}
			else if (format[i] != '%')
			{
				count = ft_putchar(format[i]);
				if (count == -1)
					return (-1);
			}
			i++;
			totalprint = totalprint + count;
		}
	}
	va_end(args);
	return (totalprint);
}

/*int	main(void)
{
	int	original;
	int	propia;

	original = printf("%d ", 10);
	propia = ft_printf("%d ", 10);
	printf("%i\n", original);
	printf("%i", propia);
	return (0);
}*/
