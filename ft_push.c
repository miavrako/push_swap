/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:45:56 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/18 11:10:08 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_operation **ops)
{
	ft_push(stack_b, stack_a);
	add_operation(ops, "pa");
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_operation **ops)
{
	ft_push(stack_a, stack_b);
	add_operation(ops, "pb");
}
