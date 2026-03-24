/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:46:56 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/24 13:44:09 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	count_total(t_operation *op)
{
	int	n;

	n = 0;
	while (op)
	{
		n++;
		op = op->next;
	}
	return (n);
}

void	print_bench(t_bench *bench)
{
	t_program	s;
	int			size;

	ft_memset(&s, 0, sizeof(t_program));
	size = stack_size(bench->a);
	bench->disorder_metric = disorder_metric(bench->a, size);
	resolve_strategy(bench);
	set_complexity(bench);
	bench->total_op = count_total(bench->operation);
	count_operations(bench->operation, &s);
	count_operations2(bench->operation, &s);
	ft_printf("[bench] disorder: %f%%\n", bench->disorder_metric);
	ft_printf("[bench] strategy: %s / %s\n", bench->strategy,
		bench->complexity);
	ft_printf("[bench] total_ops: %d\n", bench->total_op);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", s.sa, s.sb, s.ss,
		s.pa, s.pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", s.ra,
		s.rb, s.rr, s.rra, s.rrb, s.rrr);
}

void	run_bench(int active, t_stack *a, t_operation *op, char *flag)
{
	t_bench	bench;

	if (!active)
		return ;
	ft_memset(&bench, 0, sizeof(t_bench));
	bench.a = a;
	bench.operation = op;
	bench.forced_flag = flag;
	print_bench(&bench);
}
