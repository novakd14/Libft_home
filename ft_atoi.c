/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:25:59 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/20 16:43:40 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (c);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	while (ft_isspace(*(nptr + i)))
		i++;
	sign = 1;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
		if (*(nptr + i++) == '-')
			sign = -1;
	num = 0;
	while (ft_isdigit(*(nptr + i)))
		num = num * 10 + *(nptr + i++) - '0';
	return (num * sign);
}
