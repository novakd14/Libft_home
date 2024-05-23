/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:30:55 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/22 15:30:56 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*num_str;

	len = ft_intlen(n);
	num_str = (char *) malloc(sizeof(char) * (len + 1));
	if (num_str == NULL)
		return (NULL);
	*(num_str + len--) = '\0';
	if (n == 0)
		*num_str = '0';
	else if (n < 0)
		*num_str = '-';
	else
		n *= -1;
	while (n != 0)
	{
		*(num_str + len--) = '0' - n % 10;
		n /= 10;
	}
	return (num_str);
}
