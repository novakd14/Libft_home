/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fnc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 03:05:44 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 19:49:01 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	ft_print_success_short(int count)
{
	printf("\033[0;32m");
	printf(" All tests passed (%i)\n", count);
	printf("\033[0m");
}

static void	ft_print_test_int(int *test, int *ref)
{
	printf("test >>>%i<<< | ref >>>%i<<<", *test, *ref);
}

static void	ft_print_test_str(char *test, char *ref)
{
	printf("test >>>%s<<< | ref >>>%s<<<", test, ref);
}

static void	ft_print_test_bytes(unsigned char *test, unsigned char *ref, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("test >>>%x<<< | ref >>>%x<<<", *(test + i), *(ref + i));
		i++;
	}
}

static void	ft_print_input_str(char *str)
{
	printf("input >>>%s<<< -> ", str);
}

static void	ft_print_input_int(int *num)
{
	printf("input >>>%i<<< -> ", *num);
}
static void	ft_print_input_bytes(unsigned char *input, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("input >>>%x<<< -> ", *(input + i));
		i++;
	}
}

void	ft_print_fail(int index, char itype, void *input, char type, void *test, void *ref)
{
	printf("\033[0;31m");
	printf(" Test %i: ", index);
	if (itype == 's')
		ft_print_input_str(input);
	else if (itype == 'i')
		ft_print_input_int(input);
	if (type == 'i')
		ft_print_test_int(test, ref);
	if (type == 's')
		ft_print_test_str(test, ref);
	printf(" FAILED\n");
	printf("\033[0m");
}

void	ft_print_success(int index, char itype, void *input, char type, void *test, void *ref)
{
	printf(" Test %i: ", index);
	if (itype == 's')
		ft_print_input_str(input);
	else if (itype == 'i')
		ft_print_input_int(input);
	if (type == 'i')
		ft_print_test_int(test, ref);
	if (type == 's')
		ft_print_test_str(test, ref);
	printf("\033[0;32m");
	printf(" PASSED\n");
	printf("\033[0m");
}

void	ft_print_fail_bytes(int index, void *input, size_t inum, void *test, void *ref, size_t num)
{
	printf("\033[0;31m");
	printf(" Test %i: ", index);
	ft_print_input_bytes(input, inum);
	ft_print_test_bytes(test, ref, num);
	printf(" FAILED\n");
	printf("\033[0m");
}

void	ft_print_success_bytes(int index, void *input, size_t inum, void *test, void *ref, size_t num)
{
	printf(" Test %i: ", index);
	ft_print_input_bytes(input, inum);
	ft_print_test_bytes(test, ref, num);
	printf("\033[0;32m");
	printf(" PASSED\n");
	printf("\033[0m");
}

void	ft_print_bold(char *msg)
{
	printf("\033[1m");
	printf("%s", msg);
	printf("\033[0m");
}

void	ft_print_rate(int success, int max, int all)
{
	printf("==================================\n");
	if (success == max)
		printf("\033[0;32m");
	else
		printf("\033[0;31m");
	printf("%i of %i (%i) functions succesful.\n", success, max, all);
	printf("\033[0m");
}

int	ft_print_tmp(void)
{
	printf("\033[0;31m");
	printf(" Create a test!!!\n");
	printf("\033[0m");
	return (0);
}

void	ft_putnbytes(void *start, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) start;
	while (i < n - 1)
	{
		if (i % 4 == 3)
			printf("%x ", *(ptr + i++));
		else
			printf("%x:", *(ptr + i++));
	}
	printf("%x", *(ptr + i));
}
