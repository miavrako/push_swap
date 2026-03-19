/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:50:14 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/19 07:58:12 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->disorder_metric = 0.0;
	bench->strategy = NULL;
	bench->forced_flag = NULL;
	bench->total_op = 0;
	bench->operation = NULL;
	bench->complexity = NULL;
}

void	resolve_strategy(t_bench *bench)
{
	if (bench->forced_flag && !ft_strcmp(bench->forced_flag, "--simple"))
		bench->strategy = "simple";
	else if (bench->forced_flag && !ft_strcmp(bench->forced_flag, "--medium"))
		bench->strategy = "medium";
	else if (bench->forced_flag && !ft_strcmp(bench->forced_flag, "--complex"))
		bench->strategy = "complex";
	else
		set_strategy(bench);
}

void	set_strategy(t_bench *bench)
{
	if (bench->disorder_metric < 20.0)
		bench->strategy = "simple";
	else if (bench->disorder_metric < 50.0)
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
