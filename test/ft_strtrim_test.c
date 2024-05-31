/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 05:00:03 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change strtrim to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_strtrim_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, char *s1, char *set)
{
	printf("\033[36m");
	printf("%s(\"%s\", \"%s\")", name, s1, set);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, char *s1, char *set, char *expect)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 0;
	char	*users = ft_strtrim(s1, set);
	if (users == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	if (strcmp(users, expect) == 0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, s1, set); //NEED to change this function
		printf(" -> ");
		printf("users: \"%s\", expected: \"%s\"\n", users, expect); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(users);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_strtrim_test(int full)
{
	char	*name = "ft_strtrim_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test1(index++, full, name, "  42 Prague   ", " ", "42 Prague");
	check *= test1(index++, full, name, "abcDabacdjfscaabc", "abc", "Dabacdjfs");
	check *= test1(index++, full, name, "", "abc", "");
	check *= test1(index++, full, name, "aaabbcaabba", "abc", "");
	check *= test1(index++, full, name, "lorem \n ipsum \t dolor \n sit \t amet", " ", "lorem \n ipsum \t dolor \n sit \t amet");


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
