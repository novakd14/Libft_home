/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 23:24:34 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change split to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_split_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, char *s, char c)
{
	printf("\033[36m");
	printf("%s(\"%s\", \'%c\')", name, s, c);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, char *str, int c, char **expect)
{
	// 1. Setting up input

	// 2. TEST
	int		check = 1;
	size_t	i = 0;

	char **users;

	users = ft_split(str, c);
	if (users == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	while (*(users + i) != NULL && *(expect + i) != NULL && check == 1)
	{
		if (strcmp(*(users + i), *(expect + i)) != 0)
			check = 0;
		i++;
	}
	if (*(users + i) != NULL || *(expect + i) != NULL)
		check = 0;

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
		printf("users: {");
		i = 0;
		while (*(users + i) != NULL)
			printf("\"%s\", ", *(users + i++));
		printf(" NULL}, expected: {");
		i = 0;
		while (*(expect + i) != NULL)
			printf("\"%s\", ", *(expect + i++));
		printf(" NULL}\n");
	}

	// 4. Return value PASS/FAIL, and free all elements
	i = 0;
	while (*(users + i) != NULL)
		free(*(users + i++));
	free(users);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_split_test(int full)
{
	char	*name = "ft_split_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	char *solution1[] = {"123", "456", "789", NULL};
	char *solution2[] = {NULL};
	char *solution3[] = {"42Prague", NULL};
	check *= test1(index++, full, name, "123 456 789", ' ', solution1);
	check *= test1(index++, full, name, " 123 456 789 ", ' ', solution1);
	check *= test1(index++, full, name, " 123  456 789 ", ' ', solution1);
	check *= test1(index++, full, name, "\0aa\0bbb", '\0', solution2);
	check *= test1(index++, full, name, "42Prague", ' ', solution3);

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
