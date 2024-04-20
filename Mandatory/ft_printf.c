/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:46:31 by arenilla          #+#    #+#             */
/*   Updated: 2024/03/28 19:17:14 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		totalprint;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			totalprint = totalprint + ft_check(format[i], args);
			i++;
		}
		else if (format[i] != '%')
		{
			totalprint = totalprint + ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (totalprint);
}

/*int	main(void)
{
	int	original;
	int	propia;

	original = printf("%i %x\n", 387456, 4576);
	propia = ft_printf("%i %x\n", 387456, 4576);
	printf("%i\n", original);
	printf("%i", original);
	return (0);
}*/
