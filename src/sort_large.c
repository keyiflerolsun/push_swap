/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:30:00 by osancak           #+#    #+#             */
/*   Updated: 2025/07/01 14:16:59 by osancak          ###   ########.fr       */
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
	int	scanned;

	scanned = -1;
	// ft_printf("%sthreshold : %d%s\n", BLUE, threshold, RESET);
	while (lst_size(stack->a) > 3 && ++scanned < lst_size(stack->a))
	{
		if (stack->a->value >= threshold)
			rotate_a(stack, 1);
		else
		{
			push_b(stack);
			if (stack->b->value < threshold / 2)
				rotate_b(stack, 1);
			scanned = -1;
		}
	}
}

void	sort_large(t_stack *stack)
{
	int	min_val;
	int	max_val;
	int	ch_range;
	int	ch_step;
	int	ch_size;

	get_min_max(stack->a, &min_val, &max_val);
	// ft_printf("\n%smin_val  : %d\nmax_val  : %d\n", MAGENTA, min_val, max_val);
	if (lst_size(stack->a) >= 500)
		ch_size = 10;
	else if (lst_size(stack->a) >= 100)
		ch_size = 3;
	else
		ch_size = 5;
	ch_range = (max_val - min_val) / ch_size;
	// ft_printf("ch_size  : %d\nch_range : %d %s\n", ch_size, ch_range, RESET);
	ch_step = 0;
	while (++ch_step <= ch_size - 1 && lst_size(stack->a) > 3)
	{
		// ft_printf("%s\nch_step   : %d%s\n", BLUE, ch_step, RESET);
		push_chunk_to_b(stack, min_val + (ch_range * ch_step));
		// print_stacks(stack);
	}
	// ft_printf("%send-cunks%s\n\n", BLUE, RESET);
	while (lst_size(stack->a) > 3)
	{
		move_min_to_top_a(stack);
		push_b(stack);
	}
	sort_three(stack);
	// print_stacks(stack);
	while (stack->b)
	{
		move_max_to_top_b(stack);
		push_a(stack);
	}
}
