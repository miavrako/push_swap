/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 08:01:09 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/13 14:38:05 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}
static long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
static void	push_back(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*last;

	node = new_node(value);
	if (!node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = node;
}
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	**args;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (argv[1][0] == '-' && argv[1][1] == '-')
		args = argv + 2;
	i = 0;
	while (args[i])
		push_back(&a, (int)ft_atol(args[i++]));
	algo_flag(&a, &b, argv[1]);
	free_stack(a);
	free_stack(b);
	return (0);
}
/*t_stack	*stack_copy(t_stack *src)
{
	t_stack	*copy;
	t_stack	*new_node;
	t_stack	*last;

	copy = NULL;
	last = NULL;
	while (src)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
		{
			free_stack(copy);
			return (NULL);
		}
		new_node->content = src->content;
		new_node->index = src->index;
		new_node->next = NULL;
		if (!copy)
			copy = new_node;
		else
			last->next = new_node;
		last = new_node;
		src = src->next;
	}
	return (copy);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;
	char		**args;
	char		*flag;
	int			from_split;
	int			bench_on;
	t_operation	*op;

	a = NULL;
	b = NULL;
	flag = NULL;
	from_split = 0;
	op = NULL;
	bench_on = bench_activated(argc, argv);
	if (argc < 2)
		return (0);
	if (bench_on)
	{
		argc--;
		argv++;
	}
	if (argc < 2)
		print_error();
	if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		flag = argv[1];
		if (argc == 2)
			print_error();
		args = argv + 2;
	}
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		from_split = 1;
	}
	else
		args = argv + 1;
	stack_a_valid(&a, args);
	bench.a = stack_copy(a);
	bench.operation = NULL;
	if (flag)
	{
		algo_flag(&a, &b, flag);
		print_operation(op);
	}
	else
		algo_adaptive(&a, &b);
	if (bench_on)
		print_bench(&bench);
	free_stack(a);
	free_stack(b);
	free_stack(bench.a);
	if (from_split)
		free_split(args);
	return (0);
}*/
