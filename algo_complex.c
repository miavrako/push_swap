/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 07:29:40 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/05 14:26:53 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bits_needed(int n)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < n)
		bits++;
	return (bits);
}

static void	radix(t_stack **a, t_stack **b, int bit)
{
	int	n;
	int	i;

	n = stack_size(*a);
	i = 0;
	while (i < n)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	algo_complex(t_stack **a, t_stack **b)
{
	int	n;
	int	bits;
	int	bit;

	if (!*a || !(*a)->next)
		return ;
	if (!(*a)->next->next)
		return (sort_two(a, b));
	if (!(*a)->next->next->next)
		return (sort_three(a, b));
	if (stack_size(*a) <= 5)
		return (sort_five(a, b));
	n = stack_size(*a);
	assign_indices(*a);
	bits = bits_needed(n);
	bit = 0;
	while (bit < bits)
		radix(a, b, bit++);
}
