/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:56 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 15:58:15 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

// Rename in name of function and printf
int	ft_toupper_test(int full)
{
	int				check;
	int				index;

	check = 1;
	index = 1;
	(void) index;
	ft_print_bold("ft_toupper_test\n");
	check *= ft_print_tmp();
	if (check == 1)
	{
		if (full == 0)
			ft_print_success_short(index - 1);
		return (1);
	}
	else
		return (0);
}
