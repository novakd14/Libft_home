/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:26:07 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/28 20:08:49 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = (char *) malloc(sizeof (char) * (len + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + len, s2);
	return (str);
}
