/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:22:49 by osancak           #+#    #+#             */
/*   Updated: 2025/07/01 06:06:51 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * » 3 2 1
 * » 2 1 3
 * » 3 1 2
 * » 1 3 2
 * » 2 3 1
*/
void	sort_three(t_stack *stack)
{
	int	left;
	int	middle;
	int	right;

	left = stack->a->value;
	middle = stack->a->next->value;
	right = stack->a->next->next->value;
	if (left < middle && middle < right)
		return ;
	else if (left > middle && middle < right && left < right)
		swap_a(stack, 1);
	else if (left > middle && middle > right)
	{
		swap_a(stack, 1);
		reverse_a(stack, 1);
	}
	else if (left > middle && middle < right && left > right)
		rotate_a(stack, 1);
	else if (left < middle && middle > right && left < right)
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
	else if (left < middle && middle > right && left > right)
		reverse_a(stack, 1);
}

static void	sort_small(t_stack *stack)
{
	while (lst_size(stack->a) > 3 && !is_sorted(stack->a))
	{
		move_min_to_top_a(stack);
		push_b(stack);
	}
	sort_three(stack);
	while (stack->b)
		push_a(stack);
}

void	sort(t_stack *stack)
{
	if (is_sorted(stack->a))
		return ;
	if (lst_size(stack->a) == 2)
		swap_a(stack, 1);
	else if (lst_size(stack->a) == 3)
		sort_three(stack);
	else if (lst_size(stack->a) <= 5)
		sort_small(stack);
	else
		sort_large(stack);
}
