/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_check_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:59:25 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/24 13:47:08 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(char **args)
{
	if (!args || !args[0])
	{
		free(args);
		print_error();
	}
}
