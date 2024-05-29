/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 20:24:08 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change memcpy to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_memcpy_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput1(char *name, void *dest, char *src, size_t n)
{
	printf("\033[36m");
	printf("%s(%p, \"%s\", %li)", name, dest, src, n);
	printf("\033[0m");
}

static int	test_str(int index, int full, char *name, size_t size, char *src, size_t n)
{
	// 1. Setting up input
	// As a parameter

	// 2. TEST
	int		check = 0;
	void	*udest;
	void	*edest;

	udest = malloc(size);
	if (udest == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	ft_memcpy(udest, src, n);
	edest = malloc(size);
	if (edest == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	ft_memcpy(edest, src, n);
	if (memcmp(udest, edest, n) == 0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput1(name, udest, src, n); //NEED to change this function
		printf(" ->\n");
		ft_print_colored(" users:\n ", "yellow", 0);
		ft_print_mem(udest, size);
		printf("\t-> ");
		ft_print_memchar(udest, size);
		printf("\n");
		ft_print_colored(" expected:\n ", "yellow", 0);
		ft_print_mem(edest, size);
		printf("\t-> ");
		ft_print_memchar(udest, size);
		printf("\n");
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(udest);
	free(edest);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_memcpy_test(int full)
{
	char	*name = "ft_memcpy_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test_str(index++, full, name, 10, "Hello", 5);
	check *= test_str(index++, full, name, 10, "Hello", 3);
	check *= test_str(index++, full, name, 10, "Hello", 0);

	// Check style of output and print end of section
	if (index == 1)
	{
		check = 0;
		ft_print_tmp();
	}
	if (check == 1 && full == 0)
		ft_print_success_short(index - 1);
	printf("\n\n");

	// Return value PASS/FAIL
	if (check == 1)
		return (1);
	else
		return (0);
}
