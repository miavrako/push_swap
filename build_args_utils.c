/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:11:49 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/31 13:15:45 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_space_in_args(int argc, char **argv)
{
	int		i;
	char	*s;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
		{
			s = argv[i];
			while (*s)
				if (*s++ == ' ')
					return (1);
		}
		i++;
	}
	return (0);
}

int	count_total_len(int argc, char **argv)
{
	int		tot;
	int		i;
	char	*s;

	tot = 0;
	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
		{
			s = argv[i];
			while (*s)
				s++;
			tot += (s - argv[i]) + 1;
		}
		i++;
	}
	return (tot);
}

char	*join_args(int argc, char **argv, char *buf)
{
	char	*p;
	char	*s;
	int		i;

	p = buf;
	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
		{
			if (p != buf)
				*p++ = ' ';
			s = argv[i];
			while (*s)
				*p++ = *s++;
		}
		i++;
	}
	*p = '\0';
	return (buf);
}
