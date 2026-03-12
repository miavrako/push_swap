/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:03 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 23:55:39 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **stack_a, t_operation **op)
{
	ft_rotate(stack_a);
	add_operation(op, "ra");
}

void	rb(t_stack **stack_b, t_operation **op)
{
	ft_rotate(stack_b);
	add_operation(op, "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_operation **op)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	add_operation(op, "rr");
}
