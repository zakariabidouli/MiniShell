/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:25:43 by zbidouli          #+#    #+#             */
/*   Updated: 2021/12/01 23:27:09 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*math(int n, unsigned int nlen, int signe)
{	
	char			*p;
	unsigned int	i;
	unsigned int	j;

	i = n;
	j = n;
	while (i > 0)
	{
		i = i / 10;
		nlen++;
	}
	p = malloc((char)nlen + 1);
	if (!p)
		return (NULL);
	p[nlen] = '\0';
	while (nlen-- != 0)
	{
		p[nlen] = (n % 10) + '0';
		n = n / 10;
	}
	if (signe == 1)
		p[0] = '-';
	return (p);
}

char	*ft_itoa(int n)
{
	unsigned int	nlen;
	int				signe;
	char			*p;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	nlen = 0;
	signe = 0;
	if (n < 0)
	{
		nlen += 1;
		n *= (-1);
		signe = 1;
	}
	p = math(n, nlen, signe);
	return (p);
}
