/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:15:56 by osancak           #+#    #+#             */
/*   Updated: 2025/06/26 23:16:41 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 3)
		return (-1);
	stack = init_list(argv);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	swap_both(stack);
	print_stack(stack->a, 'A');
	print_stack(stack->b, 'B');
	free_stack(stack);
	return (0);
}
