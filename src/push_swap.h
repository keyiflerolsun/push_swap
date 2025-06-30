/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:07:56 by osancak           #+#    #+#             */
/*   Updated: 2025/06/30 13:47:00 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "rules.h"

t_stack	*init_list(char **argv);
void	print_stack(t_list *stack, char name);
void	print_stacks(t_stack *stack);
void	free_stack(t_stack *stack);

int		is_sorted(t_list *lst);
int		lst_size(t_list *lst);
void	move_min_to_top(t_stack *stack);
void	sort(t_stack *stack);

#endif
