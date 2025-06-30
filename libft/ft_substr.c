/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:53:26 by osancak           #+#    #+#             */
/*   Updated: 2025/06/30 11:04:50 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (ft_strlen(s) <= start)
		return (ft_calloc(1, sizeof(char)));
	if (len >= ft_strlen(s) - start)
		i = ft_strlen(s) - start + 1;
	else
		i = len + 1;
	res = malloc(i * sizeof(char));
	if (!res)
		return (NULL);
	while (*s && start--)
		s++;
	i = 0;
	while (*s && len--)
		res[i++] = *s++;
	res[i] = '\0';
	return (res);
}
