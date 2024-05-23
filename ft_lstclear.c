/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:41:41 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/23 20:16:50 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clear;
	t_list	*next;

	if (*lst == NULL)
		return ;
	clear = *lst;
	next = clear->next;
	while (next != NULL)
	{
		ft_lstdelone(clear, del);
		clear = next;
		next = clear->next;
	}
	ft_lstdelone(clear, del);
	*lst = NULL;
}
