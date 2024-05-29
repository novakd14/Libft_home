/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fnc_examples.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 03:04:14 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 16:19:15 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

// 1.	Set up input to your function by defining or adding as parameter
// 2.	Write your test. Output of this section, should be a value 0/1
//		saved in check.
// 3.	Change name of the function and its parameters, also change output.
// 4.	Free any memory if necessary
static int	test_temp(int index, int full, char *name)
{
	// 1. Setting up input
	size_t	size = 10;
	void	*mem = malloc(size);
	if (mem == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail", index);
		return (0);
	}
	memset(mem, -1, size);

	// 2. TEST
	int check;

	check = 0;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, mem, size); //NEED to change this function
		printf(" -> ");
		printf("users: %i, expected: %i\n", 5, 7); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(mem);
	if (check == 1)
		return (1);
	else
		return (0);
}

// Test for functions working with memory
static int	test_mem(int index, int full, char *name, size_t size, size_t n)
{
	// 1. Setting up input
	void	*umem = malloc(size);
	if (umem == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail", index);
		return (0);
	}
	memset(umem, -1, size);
	void	*emem = malloc(size);
	if (emem == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail", index);
		return (0);
	}
	memset(emem, -1, size);

	// 2. TEST
	int check = 0;

	ft_bzero(umem, n);
	bzero(emem, n);
	if (memcmp(umem, emem, size) == 0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, umem, n); //NEED to change this function
		printf(" ->\n");
		ft_print_colored(" users:\n ", "yellow", 0);
		ft_print_mem(umem, size);
		printf("\t-> ");
		ft_print_memchar(umem, size);
		printf("\n");
		ft_print_colored(" expected:\n ", "yellow", 0);
		ft_print_mem(emem, size);
		printf("\t-> ");
		ft_print_memchar(umem, size);
		printf("\n");
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(umem);
	free(emem);
	if (check == 1)
		return (1);
	else
		return (0);
}
