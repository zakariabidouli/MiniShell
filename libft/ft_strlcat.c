/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:03:59 by zbidouli          #+#    #+#             */
/*   Updated: 2021/12/02 00:04:40 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, size_t	dstsize)
{
	size_t	org_len;
	size_t	i;
	size_t	j;

	if (dest == NULL && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	j = ft_strlen(dest);
	org_len = j;
	if (dstsize < j || !dstsize)
		return (dstsize + ft_strlen(src));
	while (src[i] && (j < (dstsize - 1)))
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (org_len + ft_strlen(src));
}
