/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:30:00 by osancak           #+#    #+#             */
/*   Updated: 2025/07/02 19:23:26 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_min_max(t_list *lst, int *min, int *max)
{
	*min = lst->value;
	*max = lst->value;
	while (lst)
	{
		if (lst->value < *min)
			*min = lst->value;
		if (lst->value > *max)
			*max = lst->value;
		lst = lst->next;
	}
}

static void	push_chunk_to_b(t_stack *stack, int threshold)
{
	int	min_val;
	int	max_val;
	int	median;
	int	init_size;
	int	scanned;

	get_min_max(stack->a, &min_val, &max_val);
	median = (min_val + threshold) / 2;
	init_size = lst_size(stack->a);
	scanned = -1;
	while (++scanned < init_size && lst_size(stack->a) > 3)
	{
		if (!(stack->a->value < threshold))
			rotate_a(stack, 1);
		else
		{
			push_b(stack);
			if (stack->b->value < median)
				rotate_b(stack, 1);
		}
	}
}

static void	finish_sort(t_stack *stack)
{
	while (lst_size(stack->a) > 3)
	{
		move_min_to_top_a(stack);
		push_b(stack);
	}
	sort_three(stack);
	while (stack->b)
	{
		move_max_to_top_b(stack);
		push_a(stack);
	}
}

void	sort_large(t_stack *stack, int ch_size)
{
	int	min_val;
	int	max_val;
	int	ch_range;
	int	ch_step;

	get_min_max(stack->a, &min_val, &max_val);
	ch_range = (max_val - min_val + ch_size - 1) / ch_size;
	ch_step = 0;
	while (++ch_step < ch_size)
		push_chunk_to_b(stack, min_val + ch_range * ch_step);
	finish_sort(stack);
}
