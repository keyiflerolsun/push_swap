/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:50:00 by osancak           #+#    #+#             */
/*   Updated: 2025/07/01 06:06:43 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_list *lst)
{
	int	min;
	int	pos;
	int	min_pos;

	if (!lst)
		return (0);
	min = lst->value;
	pos = 0;
	min_pos = 0;
	while (lst)
	{
		if (lst->value < min)
		{
			min = lst->value;
			min_pos = pos;
		}
		pos++;
		lst = lst->next;
	}
	return (min_pos);
}

static void	move_up_a(t_stack *stack, int count)
{
	while (count--)
		rotate_a(stack, 1);
}

static void	move_down_a(t_stack *stack, int count)
{
	while (count--)
		reverse_a(stack, 1);
}

void	move_min_to_top_a(t_stack *stack)
{
	int	size;
	int	min_pos;

	if (!stack->a)
		return ;
	size = lst_size(stack->a);
	min_pos = find_min_pos(stack->a);
	if (min_pos == 0)
		return ;
	if (min_pos <= size / 2)
		move_up_a(stack, min_pos);
	else
		move_down_a(stack, size - min_pos);
}
