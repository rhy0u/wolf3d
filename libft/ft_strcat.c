/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:55:13 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/14 14:36:51 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0')
	{
		dst[size + i] = src[i];
		i++;
	}
	dst[size + i] = '\0';
	return (dst);
}
