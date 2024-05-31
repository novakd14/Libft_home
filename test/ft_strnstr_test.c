/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 03:06:50 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change strnstr to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_strnstr_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, char *big, char *little, size_t len)
{
	printf("\033[36m");
	printf("%s(\"%s\", \"%s\", %li)", name, big, little, len);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, char *big, char *little, size_t len, char *expect)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 0;
	char	*users = ft_strnstr(big, little, len);
	if (users == expect)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, big, little, len); //NEED to change this function
		printf(" -> ");
		printf("users: %s, expected: %s\n", users, expect); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_strnstr_test(int full)
{
	char	*name = "ft_strnstr_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	char	*big1 = "Welcome to 42Prague and 42Prague!";
	char	*big2 = "Welcome to 42Pragu and 42Prague!";

	check *= test1(index++, full, name, big1, "42Prague", 0, NULL);
	check *= test1(index++, full, name, big1, "42Prague", 18, NULL);
	check *= test1(index++, full, name, big1, "42Prague", 19, big1 + 11);
	check *= test1(index++, full, name, big2, "42Prague", 31, big2 + 23);
	check *= test1(index++, full, name, big1, "", 0, big1);
	check *= test1(index++, full, name, big1, "", 10, big1);
	check *= test1(index++, full, name, big1, "g", 16, NULL);
	check *= test1(index++, full, name, big1, "g", 17, big1 + 16);
	check *= test1(index++, full, name, big1, "gu", 17, NULL);
	check *= test1(index++, full, name, big1, "gu", 18, big1 + 16);
	check *= test1(index++, full, name, big1, "ge", 18, NULL);

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
