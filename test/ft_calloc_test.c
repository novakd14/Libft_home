/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 00:57:19 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change calloc to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_calloc_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, size_t nmemb, size_t size)
{
	printf("\033[36m");
	printf("%s(%li, %li)", name, nmemb, size);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, size_t nmemb, size_t size)
{
	// 1. Setting up input
	// As a parameter

	// 2. TEST
	int		check = 0;
	void	*uptr;
	void	*eptr;

	uptr = ft_calloc(nmemb, size);
	if (uptr == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	eptr = calloc(nmemb, size);
	if (eptr == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	if (memcmp(uptr, eptr, nmemb * size) == 0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, nmemb, size); //NEED to change this function
		printf(" ->\n");
		ft_print_colored(" users:\n ", "yellow", 0);
		ft_print_mem(uptr, nmemb * size);
		printf("\t-> ");
		ft_print_memchar(uptr, nmemb * size);
		printf("\n");
		ft_print_colored(" expected:\n ", "yellow", 0);
		ft_print_mem(eptr, nmemb * size);
		printf("\t-> ");
		ft_print_memchar(uptr, nmemb * size);
		printf("\n");
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(uptr);
	free(eptr);
	if (check == 1)
		return (1);
	else
		return (0);
}

static int	testNULLout(int index, int full, char *name, size_t nmemb, size_t size)
{
	// 1. Setting up input
	void	*ptr;

	// 2. TEST
	int check = 0;

	ptr = ft_calloc(nmemb, size);
	if (ptr == NULL)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, nmemb, size); //NEED to change this function
		printf(" -> ");
		printf("users: %p, expected: NULL\n", ptr); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (ptr != NULL)
		free(ptr);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_calloc_test(int full)
{
	char	*name = "ft_calloc_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test1(index++, full, name, 10, 10);
	check *= test1(index++, full, name, 100, 1);
	//check *= test1(index++, full, name, 9223372036854775807, 1);
	// Can't test, malloc not able to allocate enough memory.
	check *= testNULLout(index++, full, name, 4294967296, 4294967296);
	check *= testNULLout(index++, full, name, 2, 9223372036854775807);
	check *= testNULLout(index++, full, name, 9223372036854775807, 2);

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
