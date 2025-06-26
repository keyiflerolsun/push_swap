/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:02:27 by osancak           #+#    #+#             */
/*   Updated: 2025/06/26 20:04:22 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	t_list	*a;
	int		a_size;
	t_list	*b;
	int		b_size;
}			t_stack;

void		swap_a(t_stack *stacki, int print);
void		swap_b(t_stack *stack, int print);
void		swap_both(t_stack *stack);

void		push_a(t_stack *stack);
void		push_b(t_stack *stack);

void		rotate_a(t_stack *stack, int print);
void		rotate_b(t_stack *stack, int print);
void		rotate_both(t_stack *stack);

void		reverse_a(t_stack *stack, int print);
void		reverse_b(t_stack *stack, int print);
void		reverse_both(t_stack *stack);

#endif
