/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:36:15 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/24 17:06:02 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = 0;
	i = 0;
	while (*(s1 + i))
	{
		if (ft_strchr(set, *(s1 + i)) == NULL)
			len++;
		i++;
	}
	str = (char *) malloc(sizeof (char) * (len + 1));
	if (str == NULL)
		return (NULL);
	len = 0;
	i = 0;
	while (*(s1 + i))
	{
		if (ft_strchr(set, *(s1 + i)) == NULL)
			*(str + len++) = *(s1 + i);
		i++;
	}
	return (str);
}
