/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:38:32 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/10 15:20:23 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunks_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	count;
	int	size;

	count = 0;
	size = stack_size(*stack_a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	while (*stack_a)
	{
		if ((*stack_a)->index < count)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			count++;
		}
		else if ((*stack_a)->index < count + chunk_size)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
	}
}

static int	val_max(t_stack *stack)
{
	int	max_value;
	int	max_pos;
	int	pos;

	if (!stack)
		return (-1);
	max_value = stack->content;
	max_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->content > max_value)
		{
			max_value = stack->content;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

static void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	size;

	while (*stack_b)
	{
		max_index = val_max(*stack_b);
		size = stack_size(*stack_b);
		if (max_index <= size / 2)
		{
			while (max_index-- > 0)
				rb(stack_b);
		}
		else
		{
			while (max_index++ < size)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	algo_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*stack_a);
	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	chunks_to_b(stack_a, stack_b, chunk_size);
	push_to_a(stack_a, stack_b);
}
