/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 19:01:47 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change atoi to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_atoi_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, char *nptr)
{
	printf("\033[36m");
	printf("%s(\"%s\")", name, nptr);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, char *nptr)
{
	// 1. Setting up input
	//	set as parameter

	// 2. TEST
	int check = 0;
	int users = ft_atoi(nptr);
	int expected = atoi(nptr);

	if (users == expected)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, nptr); //NEED to change this function
		printf(" -> ");
		printf("users: %i, expected: %i\n", users, expected); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

static int	testNULL(int index, int full, char *name)
{
	// 1. Setting up input

	// 2. TEST
	int check = 0;
	int users = ft_atoi(NULL);
	int expected = 0;

	if (users == expected)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		printf("\033[36m");
		printf("%s(%s)", name, "NULL");
		printf("\033[0m");
		printf(" -> ");
		printf("users: %i, expected: %i; ", users, expected);
		ft_print_colored("without segfault\n", "orange", 0); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}


// MAIN function for all tests
int	ft_atoi_test(int full)
{
	char	*name = "ft_atoi_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test1(index++, full, name, "");
	check *= test1(index++, full, name, "0");
	check *= test1(index++, full, name, "-0");
	check *= test1(index++, full, name, "+0");
	check *= test1(index++, full, name, "1");
	check *= test1(index++, full, name, "-10");
	check *= test1(index++, full, name, "+100");
	check *= test1(index++, full, name, "2147483647");
	check *= test1(index++, full, name, "-2147483648");
	check *= test1(index++, full, name, "\t\n\v\f\r\t\n\v\f\r42");
	check *= test1(index++, full, name, "++42");
	check *= test1(index++, full, name, "--42");
	check *= testNULL(index++, full, name);

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
