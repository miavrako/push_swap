/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:50:14 by miavrako          #+#    #+#             */
/*   Updated: 2026/04/01 12:55:24 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
