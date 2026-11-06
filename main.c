/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:29:48 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/06 15:49:46 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft.h"
#include <limits.h>
#include <stdlib.h>
#define TEST_BUFF "%% this is the test string %%\n\
these should be untouched : %d%p%c%u%i%s%x%X\n"

int	long_test(void)
{
	int		n;
	char	*str;

	ft_printf("test with 0:\n");
	n = 0;
	str = NULL;
	ft_printf("%%d %d %%d\n", n);
	ft_printf("%%i %i %%i\n", n);
	ft_printf("%%c %c %%c\n", n);
	ft_printf("%%u %u %%u\n", n);
	ft_printf("%%x %x %%x\n", n);
	ft_printf("%%X %X %%X\n", n);
	ft_printf("%%p %p %%p\n", str);
	ft_printf("%%s %s %%s\n", str);
	str = malloc(1);
	str[0] = 0;
	ft_printf("test empty string:[%s]\n", str);
	ft_printf("test with positive values:\n");
	n = 'A';
	ft_printf("%%d %d %%d\n", n);
	ft_printf("%%i %i %%i\n", n);
	ft_printf("%%c %c %%c\n", n);
	ft_printf("%%u %u %%u\n", n);
	ft_printf("%%x %x %%x\n", n);
	ft_printf("%%X %X %%X\n", n);
	ft_printf("%%p %p %%p\n", str);
	ft_printf("%%s %s %%s\n", TEST_BUFF);
	ft_printf("test with negative values:\n");
	n = -42;
	ft_printf("%%d %d %%d\n", n);
	ft_printf("%%i %i %%i\n", n);
	ft_printf("%%c %c %%c\n", n);
	ft_printf("%%u %u %%u\n", n);
	ft_printf("%%x %x %%x\n", n);
	ft_printf("%%X %X %%X\n", n);
	ft_printf("%%p %p %%p\n", n);
	free(str);
	ft_printf("More tests\n");
	ft_printf("EXPECTED [ 0  1 ]\nOUTPUT   [ %c %c %c ]\n", '0', 0, '1');
	ft_printf("EXPECTED [ 2 1  ]\nOUTPUT   [ %c %c %c ]\n", '2', '1', 0);
	ft_printf("EXPECTED [  1 2 ]\nOUTPUT   [ %c %c %c ]\n", 0, '1', '2');
	ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	ft_printf("EXPECTED [ 4294967295] %u \n\n", -1);
	ft_printf("EXPECTED [ 4294967295] %u \n\n", 9223372036854775807LL);
	ft_printf("EXPECTED [ 2147483647 2147483648 4294967295 0 4294967295 0 4294967254]\nOUTPUT   [ %u %u %u %u %u %u %u]\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("EXPECTED [ 7FFFFFFF 80000000 FFFFFFFF 0 FFFFFFFF 0 FFFFFFD6]\nOUTPUT   [ %X %X %X %X %X %X %X]\n\n",
							INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	return (0);
}

#include <stdio.h>

int	short_test(void)
{
	int a = ft_printf("%%c %c %%c\n", 0);
	int b = printf("%%c %c %%c\n", 0);
	printf("ft: %d libc: %d\n", a, b);
	return (0);
}

int	main(void)
{
//	long_test();
	short_test();
	return (0);
}
