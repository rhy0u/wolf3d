/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:57:54 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/20 21:32:13 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s || start + len > ft_strlen(s))
		return (NULL);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[(size_t)start + i];
		i++;
	}
	return (res);
}
