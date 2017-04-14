/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:04:17 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/16 16:49:19 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if ((ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
				&& ft_strlen(needle) + i <= len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
