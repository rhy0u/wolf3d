/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:33:42 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/11 10:58:39 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(dst);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dst[size + i] = src[i];
		i++;
	}
	dst[size + i] = '\0';
	return (dst);
}
