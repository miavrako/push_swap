/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:00:30 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/10 21:24:45 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_adaptive(t_stack **a, t_stack **b)
{
	long	mistakes;
	int		size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size == 2)
		return (sort_two(a, b));
	if (size == 3)
		return (sort_three(a, b));
	if (size <= 5)
		return (sort_five(a, b));
	mistakes = disorder_metric(*a, size);
	if (mistakes < 0.2)
		algo_simple(a, b);
	else if (mistakes >= 0.2 && mistakes < 0.5)
		algo_medium(a, b);
	else if (mistakes >= 0.5)
		algo_complex(a, b);
}
