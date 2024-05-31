/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 12:00:31 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change lstnew to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_lstnew_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput1(char *name, char *content)
{
	printf("\033[36m");
	printf("%s(\"%s\")", name, content);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, char *content)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 1;

	t_list	*users = ft_lstnew(content);
	if (users == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}

	if (strcmp(users->content, content))
		check = 0;
	if (users->next != NULL)
		check = 0;


	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput1(name, content); //NEED to change this function
		printf(" -> content = ");
		printf("users: \"%s\", expected: \"%s\"\n", (char *) users->content, content); //NEED to change this print
		printf(" -> next = ");
		printf("users: %p, expected: %p\n", users->next, NULL); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(users);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_lstnew_test(int full)
{
	char	*name = "ft_lstnew_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	char	content[] = "Welcome to 42Prague!";
	check *= test1(index++, full, name, content);

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
