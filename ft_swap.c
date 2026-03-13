/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:11 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/13 09:25:14 by miavrako         ###   ########.fr       */
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

void	sa(t_stack **stack_a, t_program *program)
{
	ft_swap(stack_a);
	add_operation(program, "sa");
	program->sa++;
}

void	sb(t_stack **stack_b, t_program *program)
{
	ft_swap(stack_b);
	add_operation(program, "sb");
	program->sb++;
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_program *program)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	add_operation(program, "ss");
	program->ss++;
}
