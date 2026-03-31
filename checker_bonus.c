/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:49:33 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/31 13:31:53 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <limits.h>

static void	error_and_exit(t_stack *a, char **args, int from_split)
{
	free_stack(a);
	if (from_split)
		free_split(args);
	else if (args)
		free(args);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		from_split;

	if (argc < 2)
		return (0);
	from_split = 0;
	args = build_args_bonus(argc, argv, &from_split);
	init_stacks_bonus(&a, &b, args);
	if (!a)
		error_and_exit(a, args, from_split);
	if (read_and_apply(&a, &b) == 0)
	{
		cleanup_bonus(a, b, args, from_split);
		return (1);
	}
	if (is_sorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	cleanup_bonus(a, b, args, from_split);
	return (0);
}
