/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:11 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/18 11:10:58 by mirarand         ###   ########.fr       */
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
}

void	sb(t_stack **stack_b, t_operation **ops)
{
	ft_swap(stack_b);
	add_operation(ops, "sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_operation **ops)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	add_operation(ops, "ss");
}
