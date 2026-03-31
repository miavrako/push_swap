/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:27:03 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/31 09:19:41 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	return_error(t_stack *stack, char **argv, int from_split)
{
	free_stack(stack);
	if (argv)
	{
		if (from_split)
			free_split(argv);
		else
			free(argv);
	}
	print_error();
	return (0);
}

static int	is_valid_int(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	num_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if ((stack)->content == value)
			return (0);
		stack = (stack)->next;
	}
	return (1);
}

int	stack_a_valid(t_stack **stack_a, char **argv, int from_split)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!is_valid_int(argv[i]))
			return (return_error(*stack_a, argv, from_split));
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (return_error(*stack_a, argv, from_split));
		if (!num_duplicate(*stack_a, num))
			return (return_error(*stack_a, argv, from_split));
		push_back(stack_a, (int)num);
		i++;
	}
	return (1);
}
