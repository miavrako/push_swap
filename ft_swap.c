/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:11 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/13 13:35:02 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a, t_operation **ops)
{
	ft_swap(stack_a);
	add_operation(ops, "sa");
	// program->sa++;
}

void	sb(t_stack **stack_b, t_operation **ops)
{
	ft_swap(stack_b);
	add_operation(ops, "sb");
	// program->sb++;
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_operation **ops)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	add_operation(ops, "ss");
	// program->ss++;
}
