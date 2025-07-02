/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:30:00 by osancak           #+#    #+#             */
/*   Updated: 2025/07/02 06:24:47 by osancak          ###   ########.fr       */
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
		if (stack->a->value < threshold)
		{
			push_b(stack);
			if (stack->b->value < median)
				rotate_b(stack, 1);
		}
		else
			rotate_a(stack, 1);
		// print_stacks(stack);
	}
}

static void	finish_sort(t_stack *stack)
{
	while (lst_size(stack->a) > 3)
	{
		move_min_to_top_a(stack);
		push_b(stack);
	}
	// print_stacks(stack);
	sort_three(stack);
	while (stack->b)
	{
		move_max_to_top_b(stack);
		push_a(stack);
	}
	// print_stacks(stack);
}

void	sort_large(t_stack *stack)
{
	int	min_val;
	int	max_val;
	int	ch_range;
	int	ch_step;
	int	ch_size;

	if (lst_size(stack->a) >= 500)
		ch_size = 10;
	else if (lst_size(stack->a) >= 100)
		ch_size = 5;
	else
		ch_size = 2;
	get_min_max(stack->a, &min_val, &max_val);
	ch_range = (max_val - min_val + ch_size - 1) / ch_size;
	// ft_printf("%sch_size   : %d\nmin_val   : %d\nmax_val   : %d\nch_range  : %d%s\n", CYAN, ch_size, min_val, max_val, ch_range, RESET);
	ch_step = 0;
	while (++ch_step < ch_size)
	{
		// ft_printf("%sch_step %d : [%d, %d]%s\n", MAGENTA, ch_step, min_val + ch_range * (ch_step - 1), min_val + ch_range * ch_step, RESET);
		push_chunk_to_b(stack, min_val + ch_range * ch_step);
	}
	finish_sort(stack);
}
