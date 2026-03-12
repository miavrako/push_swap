/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:25:26 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/12 20:45:30 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	val_min(t_stack *stack)
{
	int	min_value;
	int	min_pos;
	int	pos;

	if (!stack)
		return (-1);
	min_value = stack->content;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->content < min_value)
		{
			min_value = stack->content;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

static void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;

	pos = val_min(*stack_a);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack_a, NULL);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack_a, NULL);
	}
	pb(stack_a, stack_b, NULL);
}

void	algo_simple(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	while (size > 3)
	{
		push_to_b(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a, stack_b);
	while (*stack_b)
		pa(stack_a, stack_b, NULL);
}
