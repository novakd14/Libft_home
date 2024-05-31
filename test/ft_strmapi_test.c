/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 01:21:19 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change strmapi to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_strmapi_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, char *s, char *fnc)
{
	printf("\033[36m");
	printf("%s(\"%s\", >%s<)", name, s, fnc);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, char *s, char (*f)(unsigned int, char), char *edest)
{
	// 1. Setting up input
	// As a parameter

	// 2. TEST
	int		check = 0;
	char	*udest;

	udest = ft_strmapi(s, f);
	if (udest == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	if (strcmp(udest, edest) == 0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, s, "char + 1"); //NEED to change this function
				printf(" -> ");
		printf("users: \"%s\", expected: \"%s\"\n", udest, edest);
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(udest);
	if (check == 1)
		return (1);
	else
		return (0);
}

static char	function1(unsigned int i, char c)
{
	(void) i;
	return (c + 1);
}

// MAIN function for all tests
int	ft_strmapi_test(int full)
{
	char	*name = "ft_strmapi_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test1(index++, full, name, "abcdefg", function1, "bcdefgh");
	check *= test1(index++, full, name, "012345678", function1, "123456789");
	check *= test1(index++, full, name, "", function1, "");

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
