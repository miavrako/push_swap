/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 07:29:40 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/13 14:29:00 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_stack **b, t_operation **op)
{
	(void)b;
	if (*a && (*a)->next && (*a)->content > (*a)->next->content)
		sa(a, op);
}

void	sort_three(t_stack **a, t_stack **b, t_operation **op)
{
	int	top;
	int	mid;
	int	bot;

	(void)b;
	top = (*a)->content;
	mid = (*a)->next->content;
	bot = (*a)->next->next->content;
	if (top > mid && mid < bot && top < bot)
		sa(a, op);
	else if (top > mid && mid > bot)
	{
		sa(a, op);
		rra(a, op);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, op);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, op);
		ra(a, op);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, op);
}

void	sort_five(t_stack **a, t_stack **b, t_operation **op)
{
	int	min_pos;
	int	size;

	while (stack_size(*a) > 3)
	{
		size = stack_size(*a);
		min_pos = find_min_index(*a);
		if (min_pos <= size / 2)
			while (min_pos-- > 0)
				ra(a, op);
		else
		{
			min_pos = size - min_pos;
			while (min_pos-- > 0)
				rra(a, op);
		}
		pb(a, b, op);
	}
	sort_three(a, b, op);
	while (*b)
		pa(a, b, op);
}
