/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sort_large.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:30:00 by osancak           #+#    #+#             */
/*   Updated: 2025/07/02 21:00:44 by osancak          ###   ########.fr       */
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
	ft_printf("%sthreshold : %d\t» min_val + ch_range * ch_step\nmedian    : %d\t» (min_val + threshold) / 2%s\n\n", MAGENTA, threshold, median, RESET);
	init_size = lst_size(stack->a);
	scanned = -1;
	while (++scanned < init_size && lst_size(stack->a) > 3)
	{
		if (!(stack->a->value < threshold))
		{
			ft_printf("%s[threshold] » !(a->value < %d)%s\n", RED, threshold, RESET);
			rotate_a(stack, 1);
			print_stacks(stack);
		}
		else
		{
			ft_printf("%s[threshold] » a->value < %d%s\n", MAGENTA, threshold, RESET);
			push_b(stack);
			print_stacks(stack);
			if (stack->b->value < median)
			{
				ft_printf("%s[median] » b->value < %d%s\n", CYAN, median, RESET);
				rotate_b(stack, 1);
				print_stacks(stack);
			}
		}
	}
}

static void	finish_sort(t_stack *stack)
{
	while (lst_size(stack->a) > 3)
	{
		ft_printf("%sa's min value pushing_b%s\n", MAGENTA, RESET);
		move_min_to_top_a(stack);
		push_b(stack);
		print_stacks(stack);
	}
	ft_printf("%s[sort_three] » a is sorting%s\n", MAGENTA, RESET);
	sort_three(stack);
	print_stacks(stack);
	while (stack->b)
	{
		ft_printf("%sb's max value pushing_a%s\n", MAGENTA, RESET);
		move_max_to_top_b(stack);
		push_a(stack);
		print_stacks(stack);
	}
}

void	sort_large(t_stack *stack, int ch_size)
{
	int	min_val;
	int	max_val;
	int	ch_range;
	int	ch_step;

	ft_printf("\n");
	print_stack(stack->a, 'A');
	ft_printf("\n");
	get_min_max(stack->a, &min_val, &max_val);
	ch_range = (max_val - min_val + ch_size - 1) / ch_size;
	ft_printf("%slst_size  : %d\nch_size   : %d\t» log₂(lst_size)\nmin_val   : %d\nmax_val   : %d\nch_range  : %d\t» (max_val - min_val + ch_size - 1) / ch_size%s\n", CYAN, lst_size(stack->a), ch_size, min_val, max_val, ch_range, RESET);
	ch_step = 0;
	while (++ch_step < ch_size)
	{
		ft_printf("\n%sch_step %d : [%d, %d]%s\n", MAGENTA, ch_step, min_val + ch_range * (ch_step - 1), min_val + ch_range * ch_step, RESET);
		push_chunk_to_b(stack, min_val + ch_range * ch_step);
	}
	ft_printf("%s\n> finish_sort <%s\n\n", MAGENTA, RESET);
	finish_sort(stack);
}
