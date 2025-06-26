/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:09:52 by osancak           #+#    #+#             */
/*   Updated: 2025/06/26 23:16:57 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

void	swap_a(t_stack *stack, int print)
{
	int	tmp;

	if (!stack->a->value || !stack->a->next->value)
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

	if (!stack->b->value || !stack->b->next->value)
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
