/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:50:14 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/13 00:16:13 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->disorder_metric = 0.0;
	bench->strategy = NULL;
	bench->total_op = 0;
	bench->operation = NULL;
	bench->complexity = NULL;
}

void	set_strategy(t_bench *bench)
{
	if (bench->disorder_metric < 20.0)
		bench->strategy = "simple";
	else if (bench->disorder_metric > 20.0 &&bench->disorder_metric < 50.0)
		bench->strategy = "medium";
	else
		bench->strategy = "complex";
}

void	set_complexity(t_bench *bench)
{
	if (!ft_strcmp(bench->strategy, "simple"))
		bench->complexity = "O(n^2)";
	else if (!ft_strcmp(bench->strategy, "medium"))
		bench->complexity = "O(n√n)";
	else
		bench->complexity = "O(n log n)";
}

void	set_total_op(t_bench *bench, t_operation *op)
{
	bench->total_op = op->op_count;
	bench->operation = op;
}

void	count_operations(t_operation *ops, t_opstats *s)
{
	while (ops)
	{
		if (!ft_strcmp(ops->operation, "sa"))
			s->sa++;
		else if (!ft_strcmp(ops->operation, "sb"))
			s->sb++;
		else if (!ft_strcmp(ops->operation, "ss"))
			s->ss++;
		else if (!ft_strcmp(ops->operation, "pa"))
			s->pa++;
		else if (!ft_strcmp(ops->operation, "pb"))
			s->pb++;
		else if (!ft_strcmp(ops->operation, "ra"))
			s->ra++;
		else if (!ft_strcmp(ops->operation, "rb"))
			s->rb++;
		else if (!ft_strcmp(ops->operation, "rr"))
			s->rr++;
		else if (!ft_strcmp(ops->operation, "rra"))
			s->rra++;
		else if (!ft_strcmp(ops->operation, "rrb"))
			s->rrb++;
		else if (!ft_strcmp(ops->operation, "rrr"))
			s->rrr++;
		ops = ops->next;
	}
}
