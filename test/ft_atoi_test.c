/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 17:28:45 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

static int	test_compare(int full, int index, char *c)
{
	int	test;
	int	ref;

	test = ft_atoi(c);
	ref = atoi(c);
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

int	ft_atoi_test(int full)
{
	int				check;
	int				index;

	check = 1;
	index = 1;
	(void) index;
	ft_print_bold("ft_atoi_test\n");
	check *= test_compare(full, index++, "0");
	check *= test_compare(full, index++, "+0");
	check *= test_compare(full, index++, "-0");
	check *= test_compare(full, index++, "1");
	check *= test_compare(full, index++, "+1");
	check *= test_compare(full, index++, "-1");
	check *= test_compare(full, index++, "2147483647");
	check *= test_compare(full, index++, "-2147483648");
	check *= test_compare(full, index++, "100");
	check *= test_compare(full, index++, "-10000");
	check *= test_compare(full, index++, "");
	check *= test_compare(full, index++, "\t\n\v\f\r 123456789");
	//check *= test_compare(full, index++, NULL);
	//ATOI function gives segmentation error
	if (check == 1)
	{
		if (full == 0)
			ft_print_success_short(index - 1);
		return (1);
	}
	else
		return (0);
}
