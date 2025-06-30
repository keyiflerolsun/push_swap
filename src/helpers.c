/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:00:37 by osancak           #+#    #+#             */
/*   Updated: 2025/06/30 11:13:39 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	err_exit(t_stack *stack)
{
	if (stack)
		free(stack);
	write(2, "\033[0;31mError\033[0m\n", 17);
	exit(1);
}

static int	is_in_list(t_list *lst, int i)
{
	int	res;

	res = 0;
	while (lst)
	{
		if (i == lst->value)
			res = 1;
		lst = lst->next;
	}
	return (res);
}

t_stack	*init_list(char **argv)
{
	t_stack	*res;
	int		tmp;

	res = malloc(sizeof(t_stack));
	if (!res)
		err_exit(res);
	while (!ft_atoi(*argv, &tmp))
		err_exit(res);
	res->a = ft_lstnew(tmp);
	res->b = NULL;
	while (*++argv && *argv)
	{
		if (!ft_atoi(*argv, &tmp) || is_in_list(res->a, tmp))
		{
			ft_lstclear(&(res->a));
			err_exit(res);
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
