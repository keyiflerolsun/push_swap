/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:10:00 by osancak           #+#    #+#             */
/*   Updated: 2025/06/29 10:09:36 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

// ? A » 1 2 3 4 5
// * A » 2 3 4 5 1
void	rotate_a(t_stack *stack, int print)
{
	t_list	*last;

	if (!stack->a || !stack->a->next)
		return ;
	last = ft_lstlast(stack->a);
	ft_lstadd_back(&stack->a, stack->a);
	stack->a = stack->a->next;
	last->next->next = NULL;
	if (print)
		ft_printf("ra\n");
}

void	rotate_b(t_stack *stack, int print)
{
	t_list	*last;

	if (!stack->b || !stack->b->next)
		return ;
	last = ft_lstlast(stack->b);
	ft_lstadd_back(&stack->b, stack->b);
	stack->b = stack->b->next;
	last->next->next = NULL;
	if (print)
		ft_printf("rb\n");
}

void	rotate_both(t_stack *stack)
{
	rotate_a(stack, 0);
	rotate_b(stack, 0);
	ft_printf("rr\n");
}
