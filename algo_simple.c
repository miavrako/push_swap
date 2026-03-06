/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:25:26 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/05 15:24:21 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_simple(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;
	int		pos;

	pos = stack_size(*stack_a) / 2;
	while (stack_size(*stack_a) > 2)
	{
		if (max > stack_a)
		{
			if (max->index <= pos)
			{
				ra(stack_a);
				pb(stack_a, stack_b);
			}
			else
			{
				rra(stack_a);
				pb(stack_a, stack_b);
			}
		}
	}
	// sort_two;
	while (*stack_b)
		pa(stack_b, stack_a);
}
