/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:17:26 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/28 20:08:53 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*(src + len))
	{
		if (len < size - 1)
		{
			*(dst + len) = *(src + len);
			*(dst + len + 1) = '\0';
		}
		len++;
	}
	return (len);
}
