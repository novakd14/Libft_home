/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:48:59 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/28 22:19:30 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Can be used with ft_strlcpy? Seems like unnecessary looping through string.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	min_len;

	min_len = 0;
	while (*(s + start + min_len))
		if (min_len == len)
			break ;
	sstr = (char *) malloc(sizeof (char) * (min_len + 1));
	if (sstr == NULL)
		return (NULL);
	min_len = 0;
	while (*(s + start + min_len) && min_len < len)
	{
		*(sstr + min_len) = *(s + start + min_len);
		min_len++;
	}
	*(sstr + min_len) = '\0';
	return (sstr);
}
