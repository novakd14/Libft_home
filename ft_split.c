/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:47:07 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/24 17:06:02 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	len;

	len = 0;
	count = 0;
	if (*(s + len) == c)
		count++;
	while (*(s + len))
	{
		if (*(s + len) == c && *(s + len))
			len++;
		count++;
		while (*(s + len) != c && *(s + len))
			len++;
	}
	return (count);
}

static size_t	ft_strlen_del(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	return (len);
}

static int	ft_check_array(char **array, size_t max_i)
{
	size_t	i;

	if (*(array + max_i) != NULL)
	{
		**(array + max_i) = '\0';
		return (1);
	}
	i = 0;
	while (i < max_i)
		free(*(array + i++));
	free(array);
	return (0);
}

static char	**ft_pop_array(char **array, char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;

	count = 0;
	if (*s == c)
	{
		*array = (char *) malloc(sizeof (char));
		if (ft_check_array(array, 0) == 0)
			return (NULL);
		count++;
	}
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			i++;
		len = ft_strlen_del(s + i, c);
		*(array + count) = (char *) malloc(sizeof (char) * (len + 1));
		if (ft_check_array(array, count) == 0)
			return (NULL);
		ft_strlcpy(*(array + count), s + i, len + 1);
		i += len;
	}
	return (array);
}

// Not happy with it!
char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**array;

	count = ft_count_words(s, c);
	array = (char **) malloc(sizeof (char *) * (count + 1));
	if (array == NULL)
		return (NULL);
	*(array + count) = NULL;
	return (ft_pop_array(array, s, c));
}
