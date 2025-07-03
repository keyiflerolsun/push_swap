/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:15:56 by osancak           #+#    #+#             */
/*   Updated: 2025/07/03 18:25:59 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	freedom(char *single, char **new_argv)
{
	int	i;

	i = 0;
	while (new_argv[i])
		free(new_argv[i++]);
	free(new_argv);
	free(single);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	*single;
	char	**new_argv;

	if (argc < 2)
		return (0);
	else
	{
		single = ft_calloc(1, sizeof(char));
		while (++argv && *argv)
		{
			if (**argv)
				single = ft_strjoin(single, *argv);
			else
				single = ft_strjoin(single, "g");
		}
	}
	new_argv = ft_split(single, ' ');
	stack = init_list(single, new_argv);
	sort(stack);
	freedom(single, new_argv);
	free_stack(stack);
	return (0);
}
