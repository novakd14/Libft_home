/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:03:25 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/20 16:23:30 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	l_len;
	int	i;
	int	j;

	l_len = ft_strlen(little);
	if (l_len == 0)
		return (big);
	i = 0;
	while (i < len && *(big + i))
	{
		if (*(big + i) == *little)
		{
			j = 1;
			while (*(big + i + j) == *(little + j) && *(little + j))
				j++;
			if (j == l_len)
				return (big + i);
		}
		i++;
	}
	return (NULL);
}
