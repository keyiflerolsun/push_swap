/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:50:00 by osancak           #+#    #+#             */
/*   Updated: 2025/07/01 07:33:00 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_list *lst)
{
	int	max;
	int	pos;
	int	max_pos;

	if (!lst)
		return (0);
	max = lst->value;
	pos = 0;
	max_pos = 0;
	while (lst)
	{
		if (lst->value > max)
		{
			max = lst->value;
			max_pos = pos;
		}
		pos++;
		lst = lst->next;
	}
	return (max_pos);
}

static void	move_up_b(t_stack *stack, int count)
{
	while (count--)
		rotate_b(stack, 1);
}

static void	move_down_b(t_stack *stack, int count)
{
	while (count--)
		reverse_b(stack, 1);
}

void	move_max_to_top_b(t_stack *stack)
{
	int	size;
	int	max_pos;

	if (!stack->b)
		return ;
	size = lst_size(stack->b);
	max_pos = find_max_pos(stack->b);
	if (max_pos == 0)
		return ;
	if (max_pos <= size / 2)
		move_up_b(stack, max_pos);
	else
		move_down_b(stack, size - max_pos);
}
