/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:24:23 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/13 13:27:50 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation(t_operation **lst, char *value)
{
	t_operation	*last;
	t_operation	*new;

	if (!lst)
		return ;
	new = (t_operation *)malloc(sizeof(t_operation));
	if (!new)
		return ;
	new->operation = value;
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
