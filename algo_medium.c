/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:38:32 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/10 19:12:00 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk;
	int	index;
	int	size;

	size = stack_size(*stack_a);
	index = 0;
	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	if (size == 100)
		chunk = size / 15;
	else
		chunk = size / 40;
	while (*stack_a)
	{
		while (index++ < size)
		{
			if ((*stack_a)->index <= index + chunk)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
