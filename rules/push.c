/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:10:05 by osancak           #+#    #+#             */
/*   Updated: 2025/06/27 16:57:03 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

void	push_a(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->b)
		return ;
	tmp = stack->b->next;
	ft_lstadd_front(&stack->a, stack->b);
	stack->b = tmp;
	ft_printf("pa\n");
}

void	push_b(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->a)
		return ;
	tmp = stack->a->next;
	ft_lstadd_front(&stack->b, stack->a);
	stack->a = tmp;
	ft_printf("pb\n");
}
