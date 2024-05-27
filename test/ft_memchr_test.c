/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 14:22:55 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

// Rename in name of function and printf
int	ft_memchr_test(void)
{
	int				check;
	int				index;

	check = 1;
	index = 1;
	(void) index;
	ft_print_bold("ft_memchr_test\n");
	check *= ft_print_tmp();
	if (check == 1)
	{
		ft_print_success();
		return (1);
	}
	else
		return (0);
}
