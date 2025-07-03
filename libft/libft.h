/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:23:46 by osancak           #+#    #+#             */
/*   Updated: 2025/07/03 17:27:26 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *nptr, int *res);

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int value);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);

int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char *s1, char *s2);

#endif
