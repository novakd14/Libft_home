/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fnc_examples.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 03:04:14 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 14:22:18 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Rename functions in test and ref declarations
static int	test_compare(int index, int c)
{
	int	test;
	int	ref;

	test = ft_NAME(c);
	ref = NAME(c);
	if (test == ref)
		return (1);
	else
	{
		ft_print_fail(index, "%i", &test, &ref);
		return (0);
	}
}
