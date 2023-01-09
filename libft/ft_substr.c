/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:18:22 by zbidouli          #+#    #+#             */
/*   Updated: 2021/12/02 00:20:12 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*p;
	size_t	i;
	size_t	end;

	if (len > (size_t)ft_strlen (s))
		len = (size_t)ft_strlen (s);
	if (start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = start;
	end = 0;
	str = (char *)s;
	while (str[start] && (end < len))
		p[end++] = str[start++];
	p[end] = '\0';
	return (p);
}
