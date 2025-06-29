/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:10:05 by osancak           #+#    #+#             */
/*   Updated: 2025/06/29 10:35:41 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

// ? A » 1 2 3 4 5
// ? B »
// * A » 2 1 3 4 5
// * B » 1
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
