/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_apply_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:40:52 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 15:17:05 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
			write(2, "Error\n", 6);
			return (0);
		}
		free(line);
	}
	return (1);
}
