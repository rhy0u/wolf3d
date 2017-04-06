/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:57:06 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/14 17:59:44 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	i = ft_strlen((char *)s);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (res);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = (char)s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
