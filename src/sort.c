/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:22:49 by osancak           #+#    #+#             */
/*   Updated: 2025/07/03 21:01:37 by osancak          ###   ########.fr       */
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

static int	get_ch_size_w_log2(int n)
{
	int	log;

	log = 0;
	if (n <= 0)
		return (0);
	while (n > 1)
	{
		n = n / 2;
		log++;
	}
	if (log < 2)
		log = 2;
	if (log > 20)
		log = 20;
	return (log);
}

void	sort(t_stack *stack)
{
	if (is_sorted(stack->a))
		return ;
	if (lst_size(stack->a) == 2)
		swap_a(stack, 1);
	else if (lst_size(stack->a) == 3)
		sort_three(stack);
	else if (lst_size(stack->a) <= 50)
		sort_small(stack);
	else
		sort_large(stack, get_ch_size_w_log2(lst_size(stack->a)));
}
