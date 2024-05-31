/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 23:34:01 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change memmove to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_memmove_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, void *dest, void *src, size_t n)
{
	printf("\033[36m");
	printf("%s(%p, %p, %li)", name, dest, src, n);
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

	udest = calloc(1, size);
	if (udest == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	ft_memmove(udest, src, n);
	edest = calloc(1, size);
	if (edest == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	memmove(edest, src, n);
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
		ft_putfncinput(name, udest, src, n); //NEED to change this function
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

static int	test_rewrite(int index, int full, char *name, size_t size, char *src, size_t n)
{
	// 1. Setting up input
	// As a parameter

	// 2. TEST
	int		check = 0;
	unsigned char	*usrc;
	unsigned char	*udest;
	unsigned char	*esrc;

	usrc = (unsigned char *) calloc(1, size);
	if (usrc == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	memcpy(usrc, src, size);
	udest = ft_memmove(usrc + 3, usrc, n);
	esrc = (unsigned char *) calloc(1, size);
	if (esrc == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	memcpy(esrc, src, size);
	memmove(esrc + 3, esrc, n);
	if (memcmp(usrc, esrc, size) == 0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, udest, usrc, n); //NEED to change this function
		printf(" ->\n");
		ft_print_colored(" users:\n ", "yellow", 0);
		ft_print_mem(usrc, size);
		printf("\t-> ");
		ft_print_memchar(usrc, size);
		printf("\n");
		ft_print_colored(" expected:\n ", "yellow", 0);
		ft_print_mem(esrc, size);
		printf("\t-> ");
		ft_print_memchar(esrc, size);
		printf("\n");
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(usrc);
	free(esrc);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_memmove_test(int full)
{
	char	*name = "ft_memmove_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test_str(index++, full, name, 10, "Hello", 5);
	check *= test_str(index++, full, name, 10, "123456", 3);
	check *= test_str(index++, full, name, 10, "123456", 0);
	check *= test_rewrite(index++, full, name, 10, "0123456789", 3);

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
