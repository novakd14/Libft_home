/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/03 09:55:13 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change strlcpy to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_strlcpy_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, char *dest, char *src, size_t n)
{
	printf("\033[36m");
	printf("%s(\"%s\", \"%s\", %li)", name, dest, src, n);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, char *dest, char *src, size_t size, char *edest, size_t elen)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 0;
	char *udest;
	if (size <= strlen(dest))
		udest = (char *) calloc(strlen(dest) + 1, sizeof (char));
	else
		udest = (char *) calloc(size, sizeof (char));
	if (udest == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	udest = strcpy(udest, dest);
	size_t ulen = ft_strlcpy(udest, src, size);
	(void) ulen;
	(void) elen;
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
		ft_putfncinput(name, dest, src, size); //NEED to change this function
		printf(" -> ");
		printf("users: \"%s\", expected: \"%s\"\n", udest, edest); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(udest);
	if (check == 1)
		return (1);
	else
		return (0);
}

static int	test2(int index, int full, char *name, char *dest, char *src, size_t size, char *edest, size_t elen)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 0;
	char *udest;
	if (size <= strlen(dest))
		udest = (char *) calloc(strlen(dest) + 1, sizeof (char));
	else
		udest = (char *) calloc(size, sizeof (char));
	if (udest == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	udest = strcpy(udest, dest);
	(void) edest;
	size_t ulen = ft_strlcpy(udest, src, size);
	if (ulen == elen)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, dest, src, size); //NEED to change this function
		printf(" -> ");
		printf("users: %li, expected: %li\n", ulen, elen); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(udest);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_strlcpy_test(int full)
{
	char	*name = "ft_strlcpy_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test1(index++, full, name, "123456789", "abcdef", 0, "123456789", 6);
	check *= test1(index++, full, name, "123456789", "abcdef", 2, "a", 6);
	check *= test1(index++, full, name, "123456789", "abcdef", 6, "abcde", 6);
	check *= test1(index++, full, name, "123456789", "abcdef", 7, "abcdef", 6);
	check *= test2(index++, full, name, "123456789", "abcdef", 0, "123456789", 6);
	check *= test2(index++, full, name, "123456789", "abcdef", 2, "a", 6);
	check *= test2(index++, full, name, "123456789", "abcdef", 6, "abcde", 6);
	check *= test2(index++, full, name, "123456789", "abcdef", 7, "abcdef", 6);

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
