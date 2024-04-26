/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:57:37 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/26 08:37:51 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"
#include <stdio.h>

static void	ft_initflags_bonus(t_format *fmt)
{
	ft_memset(fmt, 0, sizeof(t_format));
}

int	ft_printf_bonus(const char *format, ...)
{
	va_list		args;
	t_format	*fmt;
	int			total;
	int			count;

	total = 0;
	fmt = (t_format *)ft_calloc(1, sizeof(t_format));
	if (!fmt)
		return (-1);
	ft_initflags_bonus(fmt);
	va_start(args, format);
	if (format)
	{
		while (*format != '\0')
		{
			if (*format == '%' && *(++format) != '\0')
			{
				count = ft_check_bonus(format, fmt, args);
				ft_initflags_bonus(fmt);
				while (ft_strchr("+-# 0123456789*csdiuxXp%", *format))
					++format;
			}
			else if (*format != '%')
			{
				count = ft_putchar(*format);
				++format;
			}
			if (count == -1)
			{
				free(fmt);
				va_end(args);
				return (-1);
			}
			total = total + count;
		}
	}
	va_end(args);
	free(fmt);
	return (total);
}

int main(void)
{
    int original, bonus;

    // Test 1: Testing integer printing
    original = printf("Original printf: %d\n", 123);
    bonus = ft_printf_bonus("Bonus printf: %d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

    // Test 2: Testing string printing
    original = printf("Original printf: %s\n", "Hello, World!");
    bonus = ft_printf_bonus("Bonus printf: %s\n", "Hello, World!");
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

    // Test 3: Testing character printing
    original = printf("Original printf: %c\n", 'A');
    bonus = ft_printf_bonus("Bonus printf: %c\n", 'A');
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

    // Test 4: Testing hexadecimal printing
    original = printf("Original printf: %x\n", 255);
    bonus = ft_printf_bonus("Bonus printf: %x\n", 255);
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

    // Test 5: Testing pointer printing
    int num = 42;
    original = printf("Original printf: %p\n", &num);
    bonus = ft_printf_bonus("Bonus printf: %p\n", &num);
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

   // Test 1: Testing the '+' flag with integer
    original = printf("Original printf: %+d\n", 123);
    bonus = ft_printf_bonus("Bonus printf: %+d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

    // Test 2: Testing the ' ' flag with integer
    original = printf("Original printf: % d\n", 123);
    bonus = ft_printf_bonus("Bonus printf: % d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

    // Test 3: Testing the '-' flag with string
    original = printf("Original printf: %-20s\n", "Hello, World!");
    bonus = ft_printf_bonus("Bonus printf: %-20s\n", "Hello, World!");
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

    // Test 4: Testing the '0' flag with integer
    original = printf("Original printf: %010d\n", 123);
    bonus = ft_printf_bonus("Bonus printf: %010d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

    // Test 5: Testing the '#' flag with hexadecimal
    original = printf("Original printf: %#x\n", 255);
    bonus = ft_printf_bonus("Bonus printf: %#x\n", 255);
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);

    // Test 6: Testing the first test from paco
    original = printf("%-1c\n", '0');
    bonus = ft_printf_bonus("%-1c\n", '0');
    printf("Original returned: %d, Bonus returned: %d\n\n", original, bonus);


    return 0;
}
