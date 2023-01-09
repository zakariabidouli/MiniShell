/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:20:57 by zbidouli          #+#    #+#             */
/*   Updated: 2021/12/01 23:21:00 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	math(const char *s, int i)
{
	int	x;

	x = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		x *= 10;
		x += s[i] - '0';
		i++;
	}
	return (x);
}

int	ft_atoi(const char	*str)
{
	int		i;
	int		j;
	int		x;
	char	*s;

	if (!(str))
		return (0);
	i = 0;
	j = 0;
	s = (char *)str;
	while (s[i] == 32 || (9 <= s[i] && 13 >= s[i]))
		i++;
	if (s[i] == '-' && ++i)
		j++;
	else if (s[i] == '+')
		i++;
	if (!ft_strncmp(&str[i], "-2147483648", 12))
		return (-2147483648);
	x = math(s, i);
	if (j % 2)
		x = -x;
	return (x);
}
