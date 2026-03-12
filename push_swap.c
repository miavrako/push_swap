/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 08:01:09 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 14:40:42 by mirarand         ###   ########.fr       */
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
