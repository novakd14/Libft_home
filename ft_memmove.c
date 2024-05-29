/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:53:12 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/28 15:58:07 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	c;

	c = *((unsigned char *) src);
	if (n > 1)
		ft_memmove((unsigned char *) dest + 1,
			(unsigned char *) src + 1, n - 1);
	*((unsigned char *) dest) = c;
	return (dest);
}
