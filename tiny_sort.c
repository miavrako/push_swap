/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 07:29:40 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 13:25:05 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_stack **b)
{
	(void)b;
	if (*a && (*a)->next && (*a)->content > (*a)->next->content)
		sa(a);
}

void	sort_three(t_stack **a, t_stack **b)
{
	int	top;
	int	mid;
	int	bot;

	(void)b;
	top = (*a)->content;
	mid = (*a)->next->content;
	bot = (*a)->next->next->content;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;

	while (stack_size(*a) > 3)
	{
		size = stack_size(*a);
		min_pos = find_min_index(*a);
		if (min_pos <= size / 2)
			while (min_pos-- > 0)
				ra(a);
		else
		{
			min_pos = size - min_pos;
			while (min_pos-- > 0)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a, b);
	while (*b)
		pa(a, b);
}
