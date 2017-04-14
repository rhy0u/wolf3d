/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:54:52 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/21 14:03:02 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	char	*tmpsrc;
	char	*tmpdst;
	int		i;

	tmpsrc = (char *)src;
	tmpdst = (char *)dst;
	i = (int)n - 1;
	while (i >= 0)
	{
		tmpdst[i] = tmpsrc[i];
		i--;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst <= src)
		return (ft_memcpy(dst, src, n));
	else
		return (ft_memrcpy(dst, src, n));
}
