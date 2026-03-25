/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:09:39 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/25 14:29:32 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_algo_flag(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--simple") || !ft_strcmp(argv[i], "--medium")
			|| !ft_strcmp(argv[i], "--complex") || !ft_strcmp(argv[i],
				"--adaptive"))
			return (argv[i]);
		i++;
	}
	return (NULL);
}

void	algo_flag(t_stack **a, t_stack **b, char *flag, t_operation **op)
{
	if (flag && ft_strcmp(flag, "--simple") == 0)
		algo_simple(a, b, op);
	else if (flag && ft_strcmp(flag, "--medium") == 0)
		algo_medium(a, b, op);
	else if (flag && ft_strcmp(flag, "--complex") == 0)
		algo_complex(a, b, op);
	else if (flag == NULL || (flag && ft_strcmp(flag, "--adaptive") == 0))
		algo_adaptive(a, b, op);
	else
		print_error();
}

int	bench_activated(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--bench"))
			return (1);
		i++;
	}
	return (0);
}
