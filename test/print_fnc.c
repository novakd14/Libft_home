/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fnc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 03:05:44 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 12:39:06 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	ft_print_success(void)
{
	printf("\033[0;32m");
	printf(" All tests succesful.\n");
	printf("\033[0m");
}

static void	ft_print_fail_int(int *test, int *ref)
{
	printf("test >>>%i<<< | ref >>>%i<<<", *test, *ref);
}

void	ft_print_fail(int index, char type, void *test, void *ref)
{
	printf("\033[0;31m");
	printf(" Test %i: ", index);
	if (type == 'i')
		ft_print_fail_int(test, ref);
	printf("<<<\n");
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
	printf("---------------------\n");
	if (success == max)
		printf("\033[0;32m");
	else
		printf("\033[0;31m");
	printf("%i of %i (%i) succesful.\n", success, max, all);
	printf("\033[0m");
}

int	ft_print_tmp(void)
{
	printf("\033[0;31m");
	printf(" Prepare test!!!\n");
	printf("\033[0m");
	return (0);
}

// void	ft_putnbytes(char* type, void *start, int n)
// {
// 	int	step;
// 	int	i;

// 	while (i < n)
// 	if (type == "%c")
// 		printf(type, )
// 		i += 1;
// 	else if (type == "%i")
// 		printf(type, )
// 		i += 4;
// 	else
// 	{
// 		printf("Unknown type!");
// 		i = n;
// 	}
// 	{

// 	}
