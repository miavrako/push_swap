/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:24:23 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/13 00:01:47 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_lstnew(void *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	add_operation(t_operation **lst, char *operation)
{
	t_operation	*new;
	t_operation	*temp;

	new = ft_lstnew(operation);
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	}
	(*lst)->op_count++;
}

