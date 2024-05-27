/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 18:33:27 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

static int	test_compare(int full, int index, char *c)
{
	int	test;
	int	ref;

	test = ft_strlen(c);
	ref = strlen(c);
	if (test == ref)
	{
		if (full == 1)
			ft_print_success(index, 's', c, 'i', &test, &ref);
		return (1);
	}
	else
	{
		ft_print_fail(index, 's', c, 'i', &test, &ref);
		return (0);
	}
}

int	ft_strlen_test(int full)
{
	int	check;
	int	index;

	check = 1;
	index = 1;
	ft_print_bold("ft_strlen_test\n");
	check *= test_compare(full, index++, "");
	check *= test_compare(full, index++, " ");
	check *= test_compare(full, index++, "Hello");
	check *= test_compare(full, index++, "Hello world!");
	if (check == 1)
	{
		if (full == 0)
			ft_print_success_short(index - 1);
		return (1);
	}
	else
		return (0);
}
