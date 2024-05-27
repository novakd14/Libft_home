/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 12:11:39 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

static int	test_compare(int index, char *c)
{
	int	test;
	int	ref;

	test = ft_strlen(c);
	ref = strlen(c);
	if (test == ref)
		return (1);
	else
	{
		ft_print_fail(index, 'i', &test, &ref);
		return (0);
	}
}

int	ft_strlen_test(void)
{
	int	check;
	int	index;

	check = 1;
	index = 1;
	ft_print_bold("ft_strlen_test\n");
	check *= test_compare(index++, "");
	check *= test_compare(index++, " ");
	check *= test_compare(index++, "Hello");
	check *= test_compare(index++, "Hello world!");
	if (check == 1)
	{
		ft_print_success();
		return (1);
	}
	else
		return (0);
}
