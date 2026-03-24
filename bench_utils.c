/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:50:14 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/24 13:09:33 by miavrako         ###   ########.fr       */
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
		bench->strategy = "Simple";
	else if (bench->forced_flag && !ft_strcmp(bench->forced_flag, "--medium"))
		bench->strategy = "Medium";
	else if (bench->forced_flag && !ft_strcmp(bench->forced_flag, "--complex"))
		bench->strategy = "Complex";
	else
		bench->strategy = "Adaptive";
}

void	set_complexity(t_bench *bench)
{
	if (bench->forced_flag && !ft_strcmp(bench->forced_flag, "--simple"))
		bench->complexity = "O(n^2)";
	else if (bench->forced_flag && !ft_strcmp(bench->forced_flag, "--medium"))
		bench->complexity = "O(n√n)";
	else if (bench->forced_flag && !ft_strcmp(bench->forced_flag, "--complex"))
		bench->complexity = "O(n log n)";
	else
	{
		if (bench->disorder_metric < 20.0)
			bench->complexity = "O(n^2)";
		else if (bench->disorder_metric < 50.0)
			bench->complexity = "O(n√n)";
		else
			bench->complexity = "O(n log n)";
	}
}
