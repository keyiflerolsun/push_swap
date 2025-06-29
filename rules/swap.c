/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:09:52 by osancak           #+#    #+#             */
/*   Updated: 2025/06/29 10:08:04 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

// ? A » 1 2 3 4 5
// * A » 2 1 3 4 5
void	swap_a(t_stack *stack, int print)
{
	int	tmp;

	if (!stack->a || !stack->a->next)
		return ;
	tmp = stack->a->value;
	stack->a->value = stack->a->next->value;
	stack->a->next->value = tmp;
	if (print)
		ft_printf("sa\n");
}

void	swap_b(t_stack *stack, int print)
{
	int	tmp;

	if (!stack->b || !stack->b->next)
		return ;
	tmp = stack->b->value;
	stack->b->value = stack->b->next->value;
	stack->b->next->value = tmp;
	if (print)
		ft_printf("sb\n");
}

void	swap_both(t_stack *stack)
{
	swap_a(stack, 0);
	swap_b(stack, 0);
	ft_printf("ss\n");
}
