/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 20:06:26 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change lstiter to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_lstiter_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, t_list *lst, char *fnc)
{
	printf("\033[36m");
	printf("%s(%p, >%s<)", name, lst, fnc);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, t_list *lst, void (*f)(void*))
{
	// 1. Setting up input
	(void) index;
	(void) full;
	(void) name;

	// 2. TEST
	int		check = 1;
	ft_lstiter(lst, f);

	// 3. Print result of test

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

static int	test2(int index, int full, char *name, char *content, char *expect, size_t n)
{
	// 1. Setting up input
	(void) index;
	(void) full;
	(void) name;

	// 2. TEST
	int		check = 0;
	if (memcmp(content, expect, n) == 0)
		check = 1;
	// 3. Print result of test

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

static void	function1(void *str)
{
	size_t	len;

	len = strlen((char *) str);
	bzero(str, len);
}

// MAIN function for all tests
int	ft_lstiter_test(int full)
{
	char	*name = "ft_lstiter_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	char	content1[] = "ABCDE";
	char	content2[] = "12345";
	char	content3[] = "abcde";
	char	compare1[] = "ABCDE";
	char	compare23[] = "\0\0\0\0\0";
	t_list	*first = ft_lstnew(content1);
	if (first == NULL)
	{
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	t_list	*second = ft_lstnew(content2);
	if (second == NULL)
	{
		free(first);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	t_list	*last = ft_lstnew(content3);
	if (last == NULL)
	{
		free(first);
		free(second);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	first->next = second;
	second->next = last;
	check *= test1(index++, full, name, second, function1);
	check *= test2(index++, full, name, content1, compare1, 5);
	check *= test2(index++, full, name, content2, compare23, 5);
	check *= test2(index++, full, name, content3, compare23, 5);
	free(first);
	free(second);
	free(last);
	if (check == 0 || full == 1)
	{
		if (check == 1)
		{

			ft_print_colored("PASSED", "green", 0);
			printf("\tTest %i: ", index);
			ft_putfncinput(name, second, "zero out string"); //NEED to change this function
			printf(" -> Your function probably works. (check for memleak)\n");
		}
		else
		{

			ft_print_colored("FAILED", "red", 0);
			printf("\tTest %i: ", index);
			ft_putfncinput(name, second, "zero out string"); //NEED to change this function
			printf(" -> Your function doesn't use del function.");
		}
	}

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
