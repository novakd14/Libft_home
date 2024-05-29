/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 18:52:25 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change itoa to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_itoa_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, int n)
{
	printf("\033[36m");
	printf("%s(%i)", name, n);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, int n, char *estr)
{
	// 1. Setting up input
	//	set as parameter

	// 2. TEST
	int check = 0;
	char *ustr = ft_itoa(n);
	if (ustr == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}

	if (strcmp(ustr, estr) == 0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, n); //NEED to change this function
		printf(" -> ");
		printf("users: %s, expected: %s\n", ustr, estr); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(ustr);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_itoa_test(int full)
{
	char	*name = "ft_itoa_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test1(index++, full, name, 0, "0");
	check *= test1(index++, full, name, -1, "-1");
	check *= test1(index++, full, name, 1, "1");
	check *= test1(index++, full, name, 1000, "1000");
	check *= test1(index++, full, name, -1000, "-1000");
	check *= test1(index++, full, name, 1234, "1234");
	check *= test1(index++, full, name, 2147483647, "2147483647");
	check *= test1(index++, full, name, -2147483648, "-2147483648");

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
