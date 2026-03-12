/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:47:40 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 15:16:52 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	apply_rotate(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "ra") == 0)
		ft_rotate_hide(a);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rotate_hide(b);
	else if (ft_strcmp(line, "rr") == 0)
	{
		ft_rotate_hide(a);
		ft_rotate_hide(b);
	}
	else
		return (0);
	return (1);
}

int	apply_rrotate(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "rra") == 0)
		ft_rrotate_hide(a);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrotate_hide(b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_rrotate_hide(a);
		ft_rrotate_hide(b);
	}
	else
		return (0);
	return (1);
}
