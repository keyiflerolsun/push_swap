/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:10:03 by osancak           #+#    #+#             */
/*   Updated: 2025/06/26 20:04:36 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static void	cut_last(t_list *lst)
{
	while (lst && lst->next->next)
		lst = lst->next;
	lst->next = NULL;
}

void	reverse_a(t_stack *stack, int print)
{
	t_list	*last;

	if (!stack->a)
		return ;
	last = ft_lstlast(stack->a);
	cut_last(stack->a);
	ft_lstadd_front(&stack->a, last);
	if (print)
		ft_printf("rra\n");
}
void		reverse_b(t_stack *stack, int print);
void		reverse_both(t_stack *stack);
