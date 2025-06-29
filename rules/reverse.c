/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:10:03 by osancak           #+#    #+#             */
/*   Updated: 2025/06/29 10:10:11 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static void	cut_last(t_list *lst)
{
	while (lst && lst->next && lst->next->next)
		lst = lst->next;
	lst->next = NULL;
}

// ? A » 1 2 3 4 5
// * A » 5 1 2 3 4
void	reverse_a(t_stack *stack, int print)
{
	t_list	*last;

	if (!stack->a || !stack->a->next)
		return ;
	last = ft_lstlast(stack->a);
	cut_last(stack->a);
	ft_lstadd_front(&stack->a, last);
	if (print)
		ft_printf("rra\n");
}

void	reverse_b(t_stack *stack, int print)
{
	t_list	*last;

	if (!stack->b || !stack->b->next)
		return ;
	last = ft_lstlast(stack->b);
	cut_last(stack->b);
	ft_lstadd_front(&stack->b, last);
	if (print)
		ft_printf("rrb\n");
}

void	reverse_both(t_stack *stack)
{
	reverse_a(stack, 0);
	reverse_b(stack, 0);
	ft_printf("rrr\n");
}
