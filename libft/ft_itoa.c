/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:52:40 by jcentaur          #+#    #+#             */
/*   Updated: 2017/01/05 14:13:45 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_size(int n)
{
	size_t			res;
	unsigned	int	tmp;

	res = 1;
	if (n < 0)
	{
		tmp = -n;
		res++;
	}
	else
		tmp = n;
	while (tmp > 9)
	{
		res++;
		tmp /= 10;
	}
	return (res);
}

static void		ft_cheat(char *s, int n, size_t size)
{
	int				neg;
	char			tmp;
	unsigned int	ntmp;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		ntmp = -n;
		size--;
	}
	else
		ntmp = n;
	while (size > 0)
	{
		tmp = ntmp % 10 + '0';
		*s = tmp;
		ntmp /= 10;
		s++;
		size--;
	}
	if (neg)
		*s = '-';
	s[neg] = '\0';
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	size;

	size = ft_size(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	ft_cheat(res, n, size);
	ft_strrev(res);
	return (res);
}
