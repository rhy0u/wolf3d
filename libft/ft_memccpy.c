/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:53:57 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/14 14:29:39 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*tmps;
	char	*tmpd;

	i = 0;
	tmps = (char *)src;
	tmpd = (char *)dst;
	while (i < n)
	{
		tmpd[i] = tmps[i];
		if (tmps[i] == (char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
