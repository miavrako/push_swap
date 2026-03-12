/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:07 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 20:54:18 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rrotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	second_last = *stack;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a, t_operation **op)
{
	ft_rrotate(stack_a);
	add_operation(op, "rra");
}

void	rrb(t_stack **stack_b, t_operation **op)
{
	ft_rrotate(stack_b);
	add_operation(op, "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_operation **op)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	add_operation(op, "rrr");
}
