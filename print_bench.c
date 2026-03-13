/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:46:56 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/13 14:40:01 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_operation_stats(t_program *s)
{
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", s->sa, s->sb,
		s->ss, s->pa, s->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", s->ra,
		s->rb, s->rr, s->rra, s->rrb, s->rrr);
}

void	print_bench(t_bench *bench)
{
	t_program	s;
	int			size;

	ft_memset(&s, 0, sizeof(t_program));
	size = stack_size(bench->a);
	init_bench(bench);
	bench->disorder_metric = disorder_metric(bench->a, size);
	set_complexity(bench);
	set_strategy(bench);
	set_total_op(bench);
	count_operations(bench->operation, &s);
	ft_printf("[bench] disorder: %f%%\n", bench->disorder_metric);
	ft_printf("[bench] strategy: %s / %s\n", bench->strategy,
		bench->complexity);
	ft_printf("[bench] total_ops: %d\n", bench->total_op);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", s.sa, s.sb, s.ss,
		s.pa, s.pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", s.ra,
		s.rb, s.rr, s.rra, s.rrb, s.rrr);
}*/
