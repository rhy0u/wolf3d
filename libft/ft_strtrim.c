/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:20:27 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/21 15:00:31 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i < ft_strlen(s))
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j != 0)
		j--;
	if (j <= i)
		return (ft_strnew(0));
	return (ft_strsub(s, i, j - i + 1));
}
