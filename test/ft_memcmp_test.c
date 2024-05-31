/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 00:55:07 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change memcmp to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_memcmp_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput1(char *name, char *s1, char *s2, size_t n)
{
	printf("\033[36m");
	printf("%s(\"%s\", \"%s\", %li)", name, s1, s2, n);
	printf("\033[0m");
}

static int	test_str(int index, int full, char *name, void *s1, void *s2, size_t n)
{
	// 1. Setting up input
	// As a parameter

	// 2. TEST
	int	check = 0;
	int	users;
	int	expect;

	users = ft_memcmp(s1, s2, n);
	expect = ft_memcmp(s1, s2, n);
	if (SIGN(users) == SIGN(expect))
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput1(name, s1, s2, n); //NEED to change this function
		printf(" -> ");
		printf("users sign: %i, expected sign: %i\n", SIGN(users), SIGN(expect));
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

static int	test_NULL(int index, int full, char *name, void *s1, void *s2, size_t n, int expect)
{
	// 1. Setting up input
	// As a parameter

	// 2. TEST
	int	check = 0;
	int	users;

	users = ft_memcmp(s1, s2, n);
	if (SIGN(users) == SIGN(expect))
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput1(name, s1, s2, n); //NEED to change this function
		printf(" -> ");
		printf("users sign: %i, expected sign: %i\n", SIGN(users), SIGN(expect));
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_memcmp_test(int full)
{
	char	*name = "ft_memcmp_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test_str(index++, full, name, "12345", "12345", 5);
	check *= test_str(index++, full, name, "12343", "12345", 5);
	check *= test_str(index++, full, name, "12343", "1234a", 5);
	check *= test_str(index++, full, name, "1234!", "12345", 5);
	check *= test_str(index++, full, name, "12345", "12343", 5);
	check *= test_str(index++, full, name, "12345", "12343", 4);
	check *= test_str(index++, full, name, "12345", "12343", 0);
	check *= test_str(index++, full, name, "12345", NULL, 0);
	check *= test_str(index++, full, name, NULL, "12345", 0);
	check *= test_NULL(index++, full, name, NULL, NULL, 1, 0);


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
