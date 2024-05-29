/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 10:54:31 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.	Change strlcpy to name of your function.
// 2.	In ft_putfncinput change number of parameters for your function
// 3.	Add your tests, don't forget to add them in ft_strlcpy_test
//		to Tests section in format: check *= test1(index++, full, name);

#include "libft_test.h"

// Print inputs of tested function
static void	ft_putfncinput(char *name, char *dest, char *src, size_t n)
{
	printf("\033[36m");
	printf("%s(\"%s\", \"%s\", %li)", name, dest, src, n);
	printf("\033[0m");
}

// MAIN function for all tests
int	ft_strlcpy_test(int full)
{
	char	*name = "ft_strlcpy_test";
	int		check = 1;
	int		index = 1;

	// Print start of section
	ft_print_colored(name, "white", 1);
	printf("\n\n");

	// Tests -> add in format: check *= test1(index++, full, name);
	ft_putfncinput(name, "Dest", "Src", 3);

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
