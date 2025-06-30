/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:34:29 by osancak           #+#    #+#             */
/*   Updated: 2025/06/30 11:46:55 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_list *lst)
{
	int	min;
	int	pos;
	int	min_pos;

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

static void	move_up(t_stack *stack, int count)
{
	while (count--)
		rotate_a(stack, 1);
}

static void	move_down(t_stack *stack, int count)
{
	while (count--)
		reverse_a(stack, 1);
}

void	move_min_to_top(t_stack *stack)
{
	int	size;
	int	min_pos;

	size = lst_size(stack->a);
	min_pos = find_min_pos(stack->a);
	if (min_pos == 0)
		return ;
	if (min_pos <= size / 2)
		move_up(stack, min_pos);
	else
		move_down(stack, size - min_pos);
}
