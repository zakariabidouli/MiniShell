/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:03:25 by zbidouli          #+#    #+#             */
/*   Updated: 2021/12/02 00:03:49 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*out;

	size = ft_strlen(s1) + ft_strlen(s2);
	out = malloc (sizeof(char) * (size + 1));
	out[size] = '\0';
	if (out == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < ft_strlen(s1))
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j] && j < ft_strlen(s2))
	{
		out[i] = s2[j];
		i++;
		j++;
	}
	return (out);
}
