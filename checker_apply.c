/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:40:52 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/09 23:29:33 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	apply_swap(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_swap_hide(a);
	else if (ft_strcmp(line, "sb") == 0)
		ft_swap_hide(b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_swap_hide(a);
		ft_swap_hide(b);
	}
	else
		return (0);
	return (1);
}

static int	apply_push(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "pa") == 0)
		ft_push_hide(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		ft_push_hide(a, b);
	else
		return (0);
	return (1);
}

static int	apply_rotate(char *line, t_stack **a, t_stack **b)
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

static int	apply_rrotate(char *line, t_stack **a, t_stack **b)
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

static char	*get_line(void)
{
	char	*line;
	char	c;
	int		i;
	int		ret;

	line = malloc(128);
	if (!line)
		return (NULL);
	i = 0;
	ret = 1;
	while (i < 127 && ret > 0)
	{
		ret = read(0, &c, 1);
		if (ret <= 0 || c == '\n')
			break ;
		line[i++] = c;
	}
	line[i] = '\0';
	if (i == 0 && ret <= 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	read_and_apply(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_line();
		if (!line)
			break ;
		if (!apply_swap(line, a, b) && !apply_push(line, a, b)
			&& !apply_rotate(line, a, b) && !apply_rrotate(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}
