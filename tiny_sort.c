/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 07:29:40 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 23:57:35 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_stack **b)
{
	(void)b;
	if (*a && (*a)->next && (*a)->content > (*a)->next->content)
		sa(a, NULL);
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
		sa(a, NULL);
	else if (top > mid && mid > bot)
	{
		sa(a, NULL);
		rra(a, NULL);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, NULL);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, NULL);
		ra(a, NULL);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, NULL);
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
				ra(a, NULL);
		else
		{
			min_pos = size - min_pos;
			while (min_pos-- > 0)
				rra(a, NULL);
		}
		pb(a, b, NULL);
	}
	sort_three(a, b);
	while (*b)
		pa(a, b, NULL);
}
