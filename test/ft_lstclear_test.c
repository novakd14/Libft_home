/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 17:24:37 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change lstclear to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_lstclear_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, t_list **lst, char *del)
{
	printf("\033[36m");
	printf("%s(%p, %s)", name, *lst, del);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, t_list **lst, void (*del)(void*))
{
	// 1. Setting up input
	(void) index;
	(void) full;
	(void) name;

	// 2. TEST
	int		check = 1;
	ft_lstclear(lst, del);

	// 3. Print result of test

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

static void	delete2(void *str)
{
	free(str);
}

// MAIN function for all tests
int	ft_lstclear_test(int full)
{
	char	*name = "ft_lstclear_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	char	*content1 = (char *) calloc(5, sizeof(char));
	if (content1 == NULL)
	{
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	char	*content2 = (char *) calloc(5, sizeof(char));
	if (content2 == NULL)
	{
		free(content1);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	char	*content3 = (char *) calloc(5, sizeof(char));
	if (content3 == NULL)
	{
		free(content1);
		free(content2);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	t_list	*first = ft_lstnew(content1);
	if (first == NULL)
	{
		free(content1);
		free(content2);
		free(content3);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	t_list	*second = ft_lstnew(content2);
	if (second == NULL)
	{
		free(content1);
		free(content2);
		free(content3);
		free(first);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	t_list	*last = ft_lstnew(content3);
	if (last == NULL)
	{
		free(content1);
		free(content2);
		free(content3);
		free(first);
		free(second);
		ft_print_colored("MEM\tmalloc fail", "orange", 0);
		return (0);
	}
	first->next = second;
	second->next = last;
	check *= test1(index++, full, name, &second, delete2);
	free(content1);
	free(first);
	if (check == 0 || full == 1)
	{
		if (check == 1)
		{

			ft_print_colored("PASSED", "green", 0);
			printf("\tTest %i: ", index);
			ft_putfncinput(name, &second, "zero out string"); //NEED to change this function
			printf(" -> Your function probably works. (check for memleak)\n");
		}
		else
		{

			ft_print_colored("FAILED", "red", 0);
			printf("\tTest %i: ", index);
			ft_putfncinput(name, &second, "zero out string"); //NEED to change this function
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
