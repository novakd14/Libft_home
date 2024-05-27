/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_fnc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:04:47 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 15:19:07 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	ft_test_header(char *msg)
{
	unsigned int	i;
	unsigned int	len;

	len = strlen(msg);
	if (len == 0)
	{
		printf("Unit test\n==========\n");
		return ;
	}
	printf("%s\n", msg);
	i = 0;
	while (i++ < len + 1)
		printf("=");
	printf("\n");
}
