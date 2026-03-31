/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:30:49 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/31 13:34:10 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	has_space_bonus(int argc, char **argv)
{
	int		i;
	char	*s;

	i = 1;
	while (i < argc)
	{
		s = argv[i];
		while (*s)
			if (*s++ == ' ')
				return (1);
		i++;
	}
	return (0);
}

int	count_total_len_bonus(int argc, char **argv)
{
	int		tot;
	int		i;
	char	*s;

	tot = 0;
	i = 1;
	while (i < argc)
	{
		s = argv[i];
		while (*s)
			s++;
		tot += (s - argv[i]) + 1;
		i++;
	}
	return (tot);
}

char	*join_args_bonus(int argc, char **argv, char *buf)
{
	char	*p;
	char	*s;
	int		i;

	p = buf;
	i = 1;
	while (i < argc)
	{
		if (p != buf)
			*p++ = ' ';
		s = argv[i];
		while (*s)
			*p++ = *s++;
		i++;
	}
	*p = '\0';
	return (buf);
}

static char	**fill_args_bonus(int argc, char **argv)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * argc);
	if (!res)
		return (NULL);
	res[argc - 1] = NULL;
	i = 1;
	while (i < argc)
	{
		res[i - 1] = argv[i];
		i++;
	}
	return (res);
}

char	**build_args_bonus(int argc, char **argv, int *from_split)
{
	char	*buf;
	char	**res;
	int		tot;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		*from_split = 1;
		return (ft_split(argv[1], ' '));
	}
	if (!has_space_bonus(argc, argv))
		return (fill_args_bonus(argc, argv));
	tot = count_total_len_bonus(argc, argv);
	buf = malloc(tot + 1);
	if (!buf)
		return (NULL);
	res = ft_split(join_args_bonus(argc, argv, buf), ' ');
	free(buf);
	*from_split = 1;
	return (res);
}
