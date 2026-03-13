/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:27:03 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/13 15:33:35 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
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

void	stack_a_valid(t_stack **stack_a, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (argv[i])
	{
		// if (*argv[i] < '0' || *argv[i] > '9')
		// {
		// 	ft_printf("") print_error();
		// }
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			ft_printf("overflow\n");
			print_error();
		}
		if (!num_duplicate(stack_a, num))
		{
			ft_printf("duplicate\n");
			print_error();
		}
		i++;
	}
}
