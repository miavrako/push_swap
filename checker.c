/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:49:33 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/09 23:30:19 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}

static void	push_back(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*last;

	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->content = value;
	node->index = 0;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = node;
}

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

static void	init_stacks(t_stack **a, t_stack **b, int argc, char **argv)
{
	int	i;

	*a = NULL;
	*b = NULL;
	i = 1;
	while (i < argc)
	{
		push_back(a, (int)ft_atol(argv[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	init_stacks(&a, &b, argc, argv);
	if (read_and_apply(&a, &b) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	if (is_sorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(a);
	free_stack(b);
	return (0);
}
