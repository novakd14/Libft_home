/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:23:53 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/20 15:28:49 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strrchr(const char *s, int c)
{
	int	i;
	int len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (*(s + len - i) == c)
			return (s + len - i);
		i++;
	}
	return (NULL);
}
