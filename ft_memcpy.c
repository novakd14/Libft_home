/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:53:26 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/21 13:41:14 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sptr;
	unsigned char	*dptr;
	size_t			i;

	sptr = (unsigned char *) src;
	dptr = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		*(dptr + i) = *(sptr + i);
		i++;
	}
	return (dest);
}
