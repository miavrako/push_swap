/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 08:01:09 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/17 09:06:55 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

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

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*a_copy;
	t_operation	*op;
	char		**args;
	int			from_split;

	a = NULL;
	b = NULL;
	op = NULL;
	from_split = 0;
	if (argc < 2)
		return (0);
	args = build_args(argc, argv, &from_split);
	if (!args || !args[0])
		return (free(args), 0);
	stack_a_valid(&a, args);
	if (from_split)
		free_split(args);
	else
		free(args);
	a_copy = stack_copy(a);
	algo_flag(&a, &b, get_algo_flag(argc, argv), &op);
	print_operation(op);
	run_bench(bench_activated(argc, argv), a_copy, op);
	ft_lstclear(&op, NULL);
	free_stack(a_copy);
	free_stack(a);
	return (free_stack(b), 0);
}
