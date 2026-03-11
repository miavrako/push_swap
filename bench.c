/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:50:14 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/11 07:47:21 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_operations(t_stack *stack, t_bench *bench)
{
	int total;

	total = 0;
	while (stack)
	{
		total = bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb + bench->rrr
			+ bench->sa + bench->sb + bench->ss + bench->pa + bench->pb;
		stack = stack->next;
	}
	return (total);
}

void	print_bench(t_bench *bench, t_stack *stack, int size, char *strategy, char *complexity)
{
	double disorder;

	if (!bench->activated)
		return ;
	disorder = disorder_metric(stack, size);
	ft_printf("[bench] disorder: %.2f%%\n", disorder);
	ft_printf("[bench] strategy: %s / %s\n", strategy, complexity);
	ft_printf("[bench] total_ops: %d\n", bench->total_operation);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d\n", bench->sa, bench->sb, bench->ss);
	ft_printf("[bench] pa: %d, pb: %d\n", bench->pa, bench->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d\n", bench->ra, bench->rb, bench->rr);
	ft_printf("[bench] rra: %d, rrb: %d, rrr: %d\n", bench->rra, bench->rrb, bench->rrr);
}
