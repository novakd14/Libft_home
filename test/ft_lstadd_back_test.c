/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 14:22:49 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change lstadd_back to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_lstadd_back_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, t_list **lst, t_list *new)
{
	printf("\033[36m");
	printf("%s(%p, %p)", name, *lst, new);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, t_list **lst, t_list *new)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 0;
	ft_lstadd_back(lst, new);
	t_list	*users = ft_lstlast(*lst);
	if (users == new)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, lst, new); //NEED to change this function
		printf(" -> ");
		printf("users: %p, expected: %p\n", users, new); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

static int	test2(int index, int full, char *name, t_list **lst, t_list *new, t_list  *expect)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 0;
	ft_lstadd_back(lst, new);
	t_list	*users = ft_lstlast(*lst);
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
		ft_putfncinput(name, lst, new); //NEED to change this function
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
int	ft_lstadd_back_test(int full)
{
	char	*name = "ft_lstadd_back_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	char	content[] = "Just some text";
	t_list	*first = ft_lstnew(content);
	if (first == NULL)
	{
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	t_list	*second = ft_lstnew(content);
	if (second == NULL)
	{
		free(first);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	t_list	*last = ft_lstnew(content);
	if (last == NULL)
	{
		free(first);
		free(second);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	t_list	*new = ft_lstnew(content);
	if (new == NULL)
	{
		free(first);
		free(second);
		free(last);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	t_list	*null_node = NULL;
	first->next = second;
	second->next = last;
	check *= test1(index++, full, name, &first, new);
	check *= test1(index++, full, name, &null_node, new);
	check *= test2(index++, full, name, &first, NULL, new);
	free(first);
	free(second);
	free(last);
	free(new);

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
