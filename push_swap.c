/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 08:01:09 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/24 12:13:51 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_nums(int argc, char **argv)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
			n++;
		i++;
	}
	return (n);
}

static char	**fill_args(int argc, char **argv)
{
	char	**args;
	int		i;
	int		j;

	args = malloc(sizeof(char *) * (count_nums(argc, argv) + 1));
	if (!args)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
			args[j++] = argv[i];
		i++;
	}
	args[j] = NULL;
	return (args);
}

static char	**build_args(int argc, char **argv, int *from_split)
{
	if (!count_nums(argc, argv))
		return (NULL);
	if (count_nums(argc, argv) == 1 && argc == 2)
	{
		*from_split = 1;
		return (ft_split(argv[1], ' '));
	}
	return (fill_args(argc, argv));
}

static void	run_sort(t_stack **a, t_stack **b, t_operation **op, t_run *run)
{
	t_stack	*a_copy;

	a_copy = stack_copy(*a);
	algo_flag(a, b, run->flag, op);
	print_operation(*op);
	// print_count_operation(*op);
	run_bench(run->bench, a_copy, *op, run->flag);
	ft_lstclear(op, NULL);
	free_stack(a_copy);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_operation	*op;
	char		**args;
	t_run		run;

	a = NULL;
	b = NULL;
	op = NULL;
	run.from_split = 0;
	run.flag = get_algo_flag(argc, argv);
	run.bench = bench_activated(argc, argv);
	if (argc < 2)
		return (0);
	args = build_args(argc, argv, &run.from_split);
	if (!args)
		return (0);
	if (!args[0])
	{
		free(args);
		print_error();
	}
	stack_a_valid(&a, args);
	if (run.from_split)
		free_split(args);
	else
		free(args);
	if (!args[0])
	{
		free(args);
		print_error();
	}
	run_sort(&a, &b, &op, &run);
	free_stack(a);
	free_stack(b);
	return (0);
}
