/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/03 09:44:45 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change memchr to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_memchr_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput1(char *name, char *s, int c, size_t n)
{
	printf("\033[36m");
	printf("%s(\"%s\", \'%c\', %li)", name, s, c, n);
	printf("\033[0m");
}

static int	test_str(int index, int full, char *name, void *s, int c, size_t n)
{
	// 1. Setting up input
	// As a parameter

	// 2. TEST
	int		check = 0;
	void	*uptr;
	void	*eptr;

	uptr = ft_memchr(s, c, n);
	eptr = memchr(s, c, n);
	if (uptr == eptr)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput1(name, s, c, n); //NEED to change this function
		printf(" -> ");
		if (uptr != NULL || eptr != NULL)
			printf("start: %p, ", s);
		printf("users: %p", uptr);
		if (uptr != NULL)
			printf(" (%li)", uptr - s);
		printf(", expected: %p", eptr);
		if (eptr != NULL)
			printf(" (%li)", eptr - s);
		printf("\n");
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_memchr_test(int full)
{
	char	*name = "ft_memchr_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test_str(index++, full, name, "42Prague", 'P', 8);
	check *= test_str(index++, full, name, "12345", '4', 5);
	check *= test_str(index++, full, name, "1234547", '4', 7);
	check *= test_str(index++, full, name, "1234547", '4', 3);
	check *= test_str(index++, full, name, "1234547", '4', 0);
	check *= test_str(index++, full, name, "12345", '6', 5);

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
