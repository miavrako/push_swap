/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:49:33 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 15:16:29 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <limits.h>

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

static void	init_stacks(t_stack **a, t_stack **b, int argc, char **argv)
{
	long	num;
	int		i;

	*a = NULL;
	*b = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
		{
			free_stack(*a);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			free_stack(*a);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		if (!num_duplicate(*a, (int)num))
		{
			free_stack(*a);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		push_back(a, (int)num);
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
