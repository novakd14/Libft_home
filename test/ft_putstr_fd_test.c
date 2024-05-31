/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/30 02:23:51 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change putstr_fd to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_putstr_fd_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, char *s, int fd)
{
	printf("\033[36m");
	printf("%s(\"%s\", %i)", name, s, fd);
	printf("\033[0m");
}

static int	test1(int index, int full, char *name, char *s)
{
	// 1. Setting up input
	// in parameters

	// 2. TEST
	int check = 0;
	size_t	len = strlen(s);
	int fd = open("test.output", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	ft_putendl_fd(s, fd);
	close(fd);
	fd = open("test.output", O_RDONLY);
	char *buf = (char *) malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
	{
		ft_print_colored("MEM", "orange", 0);
		printf("\tTest %i: malloc fail\n", index);
		return (0);
	}
	buf[len] = '\0';
	read(fd, buf, len);
	close(fd);
	if (strcmp(buf, s) ==  0)
		check = 1;

	// 3. Print result of test
	if (check == 0 || full == 1)
	{
		if (check == 1)
			ft_print_colored("PASSED", "green", 0);
		else
			ft_print_colored("FAILED", "red", 0);
		printf("\tTest %i: ", index);
		ft_putfncinput(name, s, "file"); //NEED to change this function
		printf(" -> ");
		printf("users: \"%s\", expected: \"%s\"\n", buf, s); //NEED to change this print
	}

	// 4. Return value PASS/FAIL, and free all elements
	free(buf);
	if (check == 1)
		return (1);
	else
		return (0);
}

// MAIN function for all tests
int	ft_putstr_fd_test(int full)
{
	char	*name = "ft_putstr_fd_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	check *= test1(index++, full, name, "42Prague is the best!");
	check *= test1(index++, full, name, "");

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
