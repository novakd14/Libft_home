/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 15:58:15 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

// Rename in test and ref declaration
static int	test_compare(int full, int index, int c)
{
	int	test;
	int	ref;

	test = ft_isalnum(c);
	ref = isalnum(c);
	if (test == ref)
	{
		if (full == 1)
			ft_print_success(index, 'i', &test, &ref);
		return (1);
	}
	else
	{
		ft_print_fail(index, 'i', &test, &ref);
		return (0);
	}
}

// Rename in name of function and printf
int	ft_isalnum_test(int full)
{
	int				check;
	int				index;
	unsigned char	c;

	check = 1;
	index = 1;
	ft_print_bold("ft_isalnum_test\n");
	c = 0;
	while (c <= 128)
		check *= test_compare(full, index++, c++);
	if (check == 1)
	{
		if (full == 0)
			ft_print_success_short(index - 1);
		return (1);
	}
	else
		return (0);
}
