/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:40:22 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/20 14:46:47 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	i = 0;
	while (*(src + i))
	{
		if (len + i < size - 1)
			*(dst + len) = *(src + i);
		if (len + i == size - 1)
			*(dst + len) = '\0';
		i++;
		len++;
	}
	return (len + i);
}
