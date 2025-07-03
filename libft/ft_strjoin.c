/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:02:33 by osancak           #+#    #+#             */
/*   Updated: 2025/07/03 19:11:00 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*g_format(char *s2)
{
	char	*res;

	res = s2;
	while (*s2 && *s2 == ' ')
		s2++;
	if (!s2 || !*s2)
		res = "g";
	while (*s2)
	{
		if (!ft_isdigit(*s2) && !(*s2 == '-' || *s2 == '+' || *s2 == ' '))
			res = "g";
		s2++;
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s1_head;
	char	*res;
	int		i;

	if (!*s1 && !*s2)
		return (ft_calloc(1, sizeof(char)));
	s1_head = s1;
	s2 = g_format(s2);
	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 2), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	res[i++] = ' ';
	while (*s2)
		res[i++] = *s2++;
	free(s1_head);
	return (res);
}
