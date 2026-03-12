/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:24:23 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/13 00:09:32 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation(t_operation **lst, char *operation)
{
	t_operation	*new;
	t_operation	*temp;

	new = malloc(sizeof(t_operation));
	if (!new)
		return ;
	new->operation = operation;
	new->next = NULL;
	new->op_count = 0;
	new->a = NULL;
	new->b = NULL;
	if (!*lst)
	{
		*lst = new;
		(*lst)->op_count++;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	(*lst)->op_count++;
}

