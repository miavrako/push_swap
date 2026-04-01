/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:38:32 by mirarand          #+#    #+#             */
/*   Updated: 2026/04/01 12:46:36 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isqrt(int n)
{
	int	i;

	if (n < 0)
		return (-1);
	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	find_max_index(t_stack *stack)
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

static void	push_max_to_a(t_stack **a, t_stack **b, t_operation **op)
{
	int	pos;
	int	size;

	pos = find_max_index(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(b, op);
	}
	else
	{
		while (pos++ < size)
			rrb(b, op);
	}
	pa(a, b, op);
}

static void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b,
		int chunk, t_operation **op)
{
	int	pushed;

	pushed = 0;
	assign_indices(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= pushed)
		{
			pb(stack_a, stack_b, op);
			rb(stack_b, op);
			pushed++;
		}
		else if ((*stack_a)->index <= pushed + chunk)
		{
			pb(stack_a, stack_b, op);
			pushed++;
		}
		else
			ra(stack_a, op);
	}
}

void	algo_medium(t_stack **stack_a, t_stack **stack_b, t_operation **op)
{
	int	chunk;
	int	size;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size == 2)
		return (sort_two(stack_a, stack_b, op));
	if (size == 3)
		return (sort_three(stack_a, stack_b, op));
	if (size <= 5)
		return (sort_five(stack_a, stack_b, op));
	chunk = (ft_isqrt(size) * 3) / 2;
	if (chunk < 10)
		chunk = 10;
	push_chunks_to_b(stack_a, stack_b, chunk, op);
	while (*stack_b)
		push_max_to_a(stack_a, stack_b, op);
}
