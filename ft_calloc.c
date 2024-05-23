/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:53:52 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/22 09:19:14 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (2147483647 / nmemb > size)
		return (NULL);
	ptr = (unsigned char *) malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		*(ptr + i++) = '\0';
	return ((void *) ptr);
}
