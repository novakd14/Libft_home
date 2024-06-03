/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/03 09:44:19 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change strchr to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_strchr_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, char *s, int c)
{
	printf("\033[36m");
	printf("%s(\"%s\", \'%c\')", name, s, c);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, char *str, int c)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 0;

	char *users;
	char *expect;

	users = ft_strchr(str, c);
	expect = strchr(str, c);
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
		ft_putfncinput(name, str, c); //NEED to change this function
		printf(" -> ");
		printf("users: %p, expected: %p\n", users, expect); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_strchr_test(int full)
{
	char	*name = "ft_strchr_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test1(index++, full, name, "Ahohoj", 'h');
	check *= test1(index++, full, name, "abcdefghijkl", 'h' + 256);
	check *= test1(index++, full, name, "Ahoj", '\0');
	check *= test1(index++, full, name, "Ahoj", '\0' + 256);

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
