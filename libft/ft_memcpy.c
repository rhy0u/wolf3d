/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhy0u <jsn.centaure@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:01:03 by rhy0u             #+#    #+#             */
/*   Updated: 2016/11/14 16:26:55 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmpsrc;
	char	*tmpdst;
	size_t	i;

	tmpsrc = (char *)src;
	tmpdst = (char *)dst;
	i = 0;
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (dst);
}
