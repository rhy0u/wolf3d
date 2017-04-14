/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:14:19 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/13 17:57:30 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char const *s2)
{
	char	*res;
	char	*tmp;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
	{
		tmp = ft_strdup(s1);
		if (s1)
			free(s1);
		return (tmp);
	}
	if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		res[i + j] = s2[j];
	ft_strdel(&s1);
	return (res);
}
