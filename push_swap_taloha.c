/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_taloha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 08:01:09 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/18 11:11:48 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

// static char **get_args(int argc, char**argv, int *from_split)
// {
// 	if (argc == 2)
// 	{
// 		*from_split = 1;
// 		return (ft_split(argv[1], ' '));
// 	}
// 	return (argv + 1);
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		i;
// 	char	**args;

// 	a = NULL;
// 	b = NULL;
// 	i = 1;
// 	if (argc < 2)
// 		return (0);
// 	if (argc == 2)
// 		args = ft_split(argv[1], ' ');
// 	else
// 		args = argv + 1;
// 	if (argv[1][0] == '-' && argv[1][1] == '-')
// 		args = argv + 2;
// 	i = 0;
// 	stack_a_valid(&a, args);
// 	while (args[i])
// 		push_back(&a, (int)ft_atol(args[i++]));
// 	algo_flag(&a, &b, argv[1]);
// 	free_stack(a);
// 	free_stack(b);
// 	return (0);
//}
/*t_stack	*stack_copy(t_stack *src)
{
	t_stack	*copy;
	t_stack	*new_node;
	t_stack	*last;

	copy = NULL;
	last = NULL;
	while (src)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
		{
			free_stack(copy);
			return (NULL);
		}
		new_node->content = src->content;
		new_node->index = src->index;
		new_node->next = NULL;
		if (!copy)
			copy = new_node;
		else
			last->next = new_node;
		last = new_node;
		src = src->next;
	}
	return (copy);
}*/

// static int	is_flag(char *str)
// {
// 	return (str[0] == '-' && str[1] == '-');
// }

// int	main(int argc, char **argv)
// {
// 	t_stack		*a;
// 	t_stack		*b;
// 	t_operation	*op;
// 	char		**args;
// 	int			from_split;

// 	a = NULL;
// 	b = NULL;
// 	op = NULL;
// 	from_split = 0;
// 	if (argc < 2)
// 		return (0);
// 	args = get_args(argc, argv, &from_split);
// 	if (!args || !args[0])
// 		return (0);
// 	stack_a_valid(&a, args);
// 	if (is_flag(argv[1]))
// 		algo_flag(&a, &b, argv[1]);
// 	else
// 	{
// 		algo_adaptive(&a, &b, &op);
// 		print_operation(op);
// 		ft_lstclear(&op, NULL);
// 	}
// 	free_stack(a);
// 	free_stack(b);
// 	if (from_split)
// 		free_split(args);
// 	return (0);
// }
