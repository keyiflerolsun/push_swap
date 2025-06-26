/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:00:37 by osancak           #+#    #+#             */
/*   Updated: 2025/06/26 23:16:49 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_list(char **argv)
{
	t_stack	*res;
	int		tmp;

	res = malloc(sizeof(t_stack));
	if (!res)
		exit(1);
	while (!ft_atoi(*++argv, &tmp))
	{
		free(res);
		exit(1);
	}
	res->a = ft_lstnew(tmp);
	res->b = NULL;
	while (*++argv && *argv)
	{
		if (!ft_atoi(*argv, &tmp))
		{
			ft_lstclear(&(res->a));
			free(res);
			exit(1);
		}
		ft_lstadd_back(&(res->a), ft_lstnew(tmp));
	}
	return (res);
}

void	print_stack(t_list *stack, char name)
{
	ft_printf("\033[0;32m %c » \033[0;33m", name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\033[0m\n");
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	ft_lstclear(&(stack->a));
	ft_lstclear(&(stack->b));
	free(stack);
}
