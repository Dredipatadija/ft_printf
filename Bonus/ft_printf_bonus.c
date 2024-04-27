/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:57:37 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/27 13:34:48 by arenilla         ###   ########.fr       */
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

/*int	main(void)
{
	int	original, bonus;
	int	num = 42;
	
	// Test 1: Testing integer printing
	original = printf("O: %d\n", 123);
	bonus = ft_printf_bonus("B: %d\n", 123);
	printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 2: Testing string printing
	original = printf("O: %s\n", "Hello, World!");
	bonus = ft_printf_bonus("B: %s\n", "Hello, World!");
	printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 3: Testing character printing
	original = printf("O: %c\n", 'A');
	bonus = ft_printf_bonus("B: %c\n", 'A');
	printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 4: Testing hexadecimal printing
	original = printf("O: %x\n", 255);
	bonus = ft_printf_bonus("B: %x\n", 255);
	printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 5: Testing pointer printing
	original = printf("O: %p\n", &num);
	bonus = ft_printf_bonus("B: %p\n", &num);
	printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 6: Testing the '+' flag with integer
	original = printf("O: %+d\n", 123);
	bonus = ft_printf_bonus("B: %+d\n", 123);
	printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 7: Testing the ' ' flag with integer
    original = printf("O: % d\n", 123);
    bonus = ft_printf_bonus("B: % d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 8: Testing the '-' flag with string
    original = printf("O: %-20s\n", "Hello, World!");
    bonus = ft_printf_bonus("B: %-20s\n", "Hello, World!");
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 9: Testing the '0' flag with integer
    original = printf("O: %010d\n", 123);
    bonus = ft_printf_bonus("B: %010d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 10: Testing the '#' flag with hexadecimal
    original = printf("O: %#x\n", 255);
    bonus = ft_printf_bonus("B: %#x\n", 255);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 11: Testing the '*' flag with width specifier
    original = printf("O: %*d\n", 10, 123);
    bonus = ft_printf_bonus("B: %*d\n", 10, 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 12: Testing the '*' flag with width specifier and '-' flag
    original = printf("O: %-*d\n", 10, 123);
    bonus = ft_printf_bonus("B: %-*d\n", 10, 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 13: Testing integer printing with '+'
    original = printf("O: %+d\n", 123);
    bonus = ft_printf_bonus("B: %+d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 14: Testing integer printing with ' '
    original = printf("O: % d\n", 123);
    bonus = ft_printf_bonus("B: % d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 15: Testing string printing
    original = printf("O: %s\n", "Hello, World!");
    bonus = ft_printf_bonus("B: %s\n", "Hello, World!");
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 16: Testing character printing
    original = printf("O: %c\n", 'A');
    bonus = ft_printf_bonus("B: %c\n", 'A');
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 17: Testing hexadecimal printing with '#'
    original = printf("O: %#x\n", 255);
    bonus = ft_printf_bonus("B: %#x\n", 255);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 18: Testing pointer printing
    original = printf("O: %p\n", &num);
    bonus = ft_printf_bonus("B: %p\n", &num);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

   // Test 19: Testing the '-' flag with integer
    original = printf("O: %-10d\n", 123);
    bonus = ft_printf_bonus("B: %-10d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 20: Testing the '0' flag with integer
    original = printf("O: %010d\n", 123);
    bonus = ft_printf_bonus("B: %010d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 21: Testing the '*' flag with width specifier
    original = printf("O: %*d\n", 10, 123);
    bonus = ft_printf_bonus("B: %*d\n", 10, 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 22: Testing the '*' flag with width specifier and '-' flag
    original = printf("O: %-*d\n", 10, 123);
    bonus = ft_printf_bonus("B: %-*d\n", 10, 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 23: Testing the '*' flag with precision specifier
    original = printf("O: %.*d\n", 5, 123);
    bonus = ft_printf_bonus("B: %.*d\n", 5, 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 24: Testing integer printing with '0'
    original = printf("O: %05d\n", 123);
    bonus = ft_printf_bonus("B: %05d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 25: Testing integer printing with width and precision
    original = printf("O: %10.5d\n", 123);
    bonus = ft_printf_bonus("B: %10.5d\n", 123);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 26: Testing string printing with '*'
    original = printf("O: %*s\n", 10, "Hello");
    bonus = ft_printf_bonus("B: %*s\n", 10, "Hello");
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 27: Testing character printing with '*'
    original = printf("O: %*c\n", 10, 'A');
    bonus = ft_printf_bonus("B: %*c\n", 10, 'A');
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 28: Testing hexadecimal printing with '0'
    original = printf("O: %010x\n", 255);
    bonus = ft_printf_bonus("B: %010x\n", 255);
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

    // Test 29: Testing hexadecimal printing with width and precision
	original = printf("O: %10.5x\n", 255);
	bonus = ft_printf_bonus("B: %10.5x\n", 255);
   	printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	return 0;
}*/
