/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:56:13 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/18 11:04:23 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstdelone(t_operation *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->operation);
	free(lst);
}

void	ft_lstclear(t_operation **lst, void (*del)(void *))
{
	t_operation	*t;

	if (!lst)
		return ;
	while (*lst)
	{
		t = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = t;
	}
	*lst = NULL;
}
