/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fnc_examples.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 03:04:14 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 19:08:52 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

// Rename functions in test and ref declarations
static int	test_compare(int full, int index, int c)
{
	int	test;
	int	ref;

	test = ft_NAME(c);
	ref = NAME(c);
	if (test == ref)
	{
		if (full == 1)
			ft_print_success(index, 'i', &c, 'i', &test, &ref);
		return (1);
	}
	else
	{
		ft_print_fail(index, 'i', &c, 'i', &test, &ref);
		return (0);
	}
}

static int	test_compare_bytes(int full, int index, void *s, size_t n)
{
	unsigned char	*tmp_test;
	unsigned char	*tmp_ref;
	unsigned char	*test;
	unsigned char	*ref;

	test = ft_NAME(s, n);
	ref = NAME(s, n);
	if (memcmp(test, ref, n) == 0)
	{
		if (full == 1)
			ft_print_success_bytes(index, s, n, &test, &ref, n);
		return (1);
	}
	else
	{
		ft_print_fail_bytes(index, s, n, &test, &ref, n);
		return (0);
	}
}
