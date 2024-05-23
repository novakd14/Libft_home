/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:50:26 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/23 20:18:46 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checknew(t_list *new, t_list *new_list, void (*del)(void *))
{
	if (new == NULL)
	{
		ft_lstclear(&new_list, del);
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*orig;
	t_list	*new;


	if (lst == NULL)
		return (NULL);
	new_list = NULL;
	orig = lst;
	while (orig->next != NULL)
	{
		new = ft_lstnew(f(orig->content));
		if (ft_checknew(new, new_list, del) == 0)
			return (NULL);
		ft_lstadd_back(&new_list, new);
		orig = orig->next;
	}
	new = ft_lstnew(f(orig->content));
	if (ft_checknew(new, new_list, del) == 0)
		return (NULL);
	ft_lstadd_back(&new_list, new);
	return (new_list);
}
