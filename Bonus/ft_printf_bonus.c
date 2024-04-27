/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:57:37 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/27 21:26:47 by arenilla         ###   ########.fr       */
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
				while (ft_strchr(".+-# 0123456789*csdiuxXp%", *format))
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

/*	// Tests with %c, must'n use 0, #, +, ' ' or ., not gotten by original printf
	// Test 1: Testing %c specifier with width
	original = printf("O: %2c\n", 'A');
	bonus = ft_printf_bonus("R: %2c\n", 'A');
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

   // Test 2: Testing %c specifier
    original = printf("O: %c\n", 'A');
    bonus = ft_printf_bonus("B: %c\n", 'A');
    printf("Original returned: %d, Bonus returned: %d\n", original, bonus);
    if (original == bonus)
        printf("OK\n\n");
    else
        printf("KO\n\n");

	// Test 3: Testing %c specifier with left alignment
	original = printf("O: %-4c\n", 'B');
	bonus = ft_printf_bonus("R: %-4c\n", 'B');
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 4: Testing %c specifier with width and left alignment (larger width)
	original = printf("O: %6c\n", 'C');
	bonus = ft_printf_bonus("R: %6c\n", 'C');
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 5: Testing %c specifier with width and left alignment (larger width)
	original = printf("O: %8c\n", 'D');
	bonus = ft_printf_bonus("R: %8c\n", 'D');
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 6: Testing %c specifier with width and left alignment (larger width)
	original = printf("O: %10c\n", 'E');
	bonus = ft_printf_bonus("R: %10c\n", 'E');
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 7: Testing %c specifier without flags
	original = printf("O: %c\n", 'F');
	bonus = ft_printf_bonus("R: %c\n", 'F');
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");*/

/*	//Tests with %s, must'n use 0, #, + or ' ', not gotten by origginal printf
	// Test 1: Testing %s specifier with width
	original = printf("O: %10s\n", "Hello");
	bonus = ft_printf_bonus("R: %10s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 2: Testing %s specifier with left alignment
	original = printf("O: %-10s\n", "Hello");
	bonus = ft_printf_bonus("R: %-10s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 3: Testing %s specifier with width and left alignment (larger width)
	original = printf("O: %15s\n", "Hello");
	bonus = ft_printf_bonus("R: %15s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 4: Testing %s specifier with width and left alignment (larger width)
	original = printf("O: %20s\n", "Hello");
	bonus = ft_printf_bonus("R: %20s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 5: Testing %s specifier with precision
	original = printf("O: %.3s\n", "Hello");
	bonus = ft_printf_bonus("R: %.3s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 6: Testing %s specifier with precision and width
	original = printf("O: %10.3s\n", "Hello");
	bonus = ft_printf_bonus("R: %10.3s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 7: Testing %s specifier with precision and left alignment
	original = printf("O: %-10.3s\n", "Hello");
	bonus = ft_printf_bonus("R: %-10.3s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 8: Testing %s specifier with precision, width and left alignment
	original = printf("O: %-15.3s\n", "Hello");
	bonus = ft_printf_bonus("R: %-15.3s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 9: Testing %s specifier with precision (larger than string length)
	original = printf("O: %.10s\n", "Hello");
	bonus = ft_printf_bonus("R: %.10s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 10: Testing %s specifier without flags
	original = printf("O: %s\n", "Hello");
	bonus = ft_printf_bonus("R: %s\n", "Hello");
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");*/

	// Tests for %p, must'n use 0, ., #, or +
	// Test 1: Testing %p specifier with width
	void *ptr1 = (void *)0x12345678;
	original = printf("O: %10p\n", ptr1);
	bonus = ft_printf_bonus("R: %10p\n", ptr1);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 2: Testing %p specifier with left alignment
	void *ptr2 = (void *)0x87654321;
	original = printf("O: %-10p\n", ptr2);
	bonus = ft_printf_bonus("R: %-10p\n", ptr2);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 3: Testing %p specifier with width and left alignment (larger width)
	void *ptr3 = (void *)0xabcdef;
	original = printf("O: %15p\n", ptr3);
	bonus = ft_printf_bonus("R: %15p\n", ptr3);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 4: Testing %p specifier with width and left alignment (larger width)
	void *ptr4 = (void *)0x98765432;
	original = printf("O: %20p\n", ptr4);
	bonus = ft_printf_bonus("R: %20p\n", ptr4);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 5: Testing %p specifier with width and left alignment (larger width)
	void *ptr5 = (void *)0xabcdef;
	original = printf("O: %25p\n", ptr5);
	bonus = ft_printf_bonus("R: %25p\n", ptr5);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 6: Testing %p specifier with width and left alignment (larger width)
	void *ptr6 = (void *)0x12345678;
	original = printf("O: %30p\n", ptr6);
	bonus = ft_printf_bonus("R: %30p\n", ptr6);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 7: Testing %p specifier without flags
	void *ptr7 = (void *)0x87654321;
	original = printf("O: %p\n", ptr7);
	bonus = ft_printf_bonus("R: %p\n", ptr7);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 8: Testing %p specifier with width and left alignment
	void *ptr8 = (void *)0xabcdef;
	original = printf("O: %-20p\n", ptr8);
	bonus = ft_printf_bonus("R: %-20p\n", ptr8);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 9: Testing %p specifier with width and left alignment (larger width)
	void *ptr9 = (void *)0x12345678;
	original = printf("O: %-30p\n", ptr9);
	bonus = ft_printf_bonus("R: %-30p\n", ptr9);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");

	// Test 10: Testing %p specifier with width and left alignment (larger width)
	void *ptr10 = (void *)0xabcdef;
	original = printf("O: %-35p\n", ptr10);
	bonus = ft_printf_bonus("R: %-35p\n", ptr10);
	printf("Return Original: %d, Return Réplica: %d\n", original, bonus);
	if (original == bonus)
		printf("OK\n\n");
	else
		printf("KO\n\n");
     return 0;
}
