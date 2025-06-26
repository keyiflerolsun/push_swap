/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:00:37 by osancak           #+#    #+#             */
/*   Updated: 2025/06/26 20:52:49 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_list(char **argv)
{
	t_stack	*res;
	int		tmp;

	res = malloc(sizeof(t_stack));
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
			free(res);
			exit(1);
		}
		ft_lstadd_back(&(res->a), ft_lstnew(tmp));
	}
	return (res);
}
