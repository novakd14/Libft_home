/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 20:59:50 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change lstmap to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_lstmap_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, t_list *lst, char *f, char *del)
{
	printf("\033[36m");
	printf("%s(%p, >%s<, >%s<)", name, lst, f, del);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, t_list *lst, void *(*f)(void *), void (*del)(void *), t_list **new_lst)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 0;
	*new_lst = ft_lstmap(lst, f, del);
	if (ft_lstsize(*new_lst) == ft_lstsize(lst))
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, lst, "copy content", "free content"); //NEED to change this function
		printf(" -> ");
		printf("users: %i, expected: %i\n", ft_lstsize(*new_lst), ft_lstsize(lst)); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

static int	test2(int index, int full, char *name, t_list *lst, char *expect, size_t n)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 0;
	if (memcmp(lst->content, expect, n) == 0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, lst, "copy content", "free content"); //NEED to change this function
		printf(" -> ");
		printf("users: %s, expected: %s\n", (char *) lst->content, expect); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	if (check == 1)
		return (1);
	else
		return (0);
}

static void	*function1(void *str)
{
	size_t	len;
	void	*ptr;

	len = ft_strlen((char *) str);
	ptr = calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	return (strncpy(ptr, str, len));
}

static void	delete1(void *str)
{
	free(str);
}

// MAIN function for all tests
int	ft_lstmap_test(int full)
{
	char	*name = "ft_lstmap_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	char	content1[] = "ABCDE";
	char	content2[] = "abcde";
	char	content3[] = "12345";
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
	t_list	*new_list;
	check *= test1(index++, full, name, first, function1, delete1, &new_list);
	check *= test2(index++, full, name, new_list, content1, 5);
	check *= test2(index++, full, name, new_list->next, content2, 5);
	check *= test2(index++, full, name, new_list->next->next, content3, 5);
	free(first);
	free(second);
	free(last);
	ft_lstclear(&new_list, delete1);
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
