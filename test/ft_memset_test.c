/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 02:31:45 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change memset to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_memset_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, void *s, int c, size_t n)
{
	printf("\033[36m");
	printf("%s(%p, \'%c\', %li)", name, s, c, n);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, size_t size, int c, size_t n)
{
	// 1. Setting up input
	void	*umem = malloc(size);
	if (umem == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	bzero(umem, size);
	void	*emem = malloc(size);
	if (emem == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	bzero(emem, size);

	// 2. TEST
	int check = 0;

	ft_memset(umem, c, n);
	memset(emem, c, n);
	if (memcmp(umem, emem, size) == 0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, umem, c, n); //NEED to change this function
		printf(" ->\n");
		ft_print_colored(" users:\n ", "yellow", 0);
		ft_print_mem(umem, size);
		printf("\t-> ");
		ft_print_memchar(umem, size);
		printf("\n");
		ft_print_colored(" expected:\n ", "yellow", 0);
		ft_print_mem(emem, size);
		printf("\t-> ");
		ft_print_memchar(umem, size);
		printf("\n");
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(umem);
	free(emem);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_memset_test(int full)
{
	char	*name = "ft_memset_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test1(index++, full, name, 6, 'a', 6);
	check *= test1(index++, full, name, 6, 0, 6);
	check *= test1(index++, full, name, 6, -1, 6);
	check *= test1(index++, full, name, 6, 'a', 0);
	check *= test1(index++, full, name, 6, 'a', 1);

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
