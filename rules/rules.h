/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:02:27 by osancak           #+#    #+#             */
/*   Updated: 2025/06/30 08:26:55 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}			t_stack;

// ? A » 1 2 3 4 5
// * A » 2 1 3 4 5
void		swap_a(t_stack *stack, int print);
void		swap_b(t_stack *stack, int print);
void		swap_both(t_stack *stack);

// ? A » 1 2 3 4 5
// ? B »
// * A » 2 1 3 4 5
// * B » 1
void		push_b(t_stack *stack);
void		push_a(t_stack *stack);

// ? A » 1 2 3 4 5
// * A » 2 3 4 5 1
void		rotate_a(t_stack *stack, int print);
void		rotate_b(t_stack *stack, int print);
void		rotate_both(t_stack *stack);

// ? A » 1 2 3 4 5
// * A » 5 1 2 3 4
void		reverse_a(t_stack *stack, int print);
void		reverse_b(t_stack *stack, int print);
void		reverse_both(t_stack *stack);

#endif
