/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_check_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:59:25 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/19 14:02:32 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	t_run	run;

	run.from_split = 0;
	if (run.from_split)
		free_split(args);
	else
		free(args);
}

void	check_args(char **args)
{
	if (!args[0])
	{
		free(args);
		print_error();
	}
}
