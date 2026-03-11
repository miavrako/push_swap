/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:38:32 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/11 11:08:59 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max_to_a(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	pos = find_min_index(*b);
	size = stack_size(*b);

	if (pos <= size / 2)
		while (pos--)
			rb(b);
	else
		while (pos++ < size)
			rrb(b);

	pa(a, b);
}

void	algo_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk;
	int	pushed;
	int	size;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 100)
		chunk = 15;
	else
		chunk = 30;
	pushed = 0;
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
	while (*stack_b)
		push_max_to_a(stack_a, stack_b);
}
