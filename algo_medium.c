/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:38:32 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/11 13:43:37 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int	max;
	int	idx;
	int	pos;

	if (!stack)
		return (-1);
	max = stack->content;
	idx = 0;
	pos = 0;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			idx = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (idx);
}

void	push_max_to_a(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	pos = find_max_index(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
		while (pos--)
			rb(b);
	else
		while (pos++ < size)
			rrb(b);
	pa(a, b);
}

static void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b, int chunk)
{
	int	pushed;

	pushed = 0;
	assign_indices(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= pushed)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			pushed++;
		}
		else if ((*stack_a)->index <= pushed + chunk)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
}

void	algo_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk;
	int	size;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	chunk = (size <= 100) ? 15 : 30;
	push_chunks_to_b(stack_a, stack_b, chunk);
	while (*stack_b)
		push_max_to_a(stack_a, stack_b);
}
