/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:15:56 by osancak           #+#    #+#             */
/*   Updated: 2025/06/27 20:35:38 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stacks(t_stack *stack)
{
	print_stack(stack->a, 'A');
	print_stack(stack->b, 'B');
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 3)
		return (-1);
	stack = init_list(argv);
	print_stacks(stack);
	reverse_a(stack, 1);
	print_stacks(stack);
	return (0);
}
