/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:48:11 by jcentaur          #+#    #+#             */
/*   Updated: 2016/11/17 16:18:47 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (i == 0)
		{
			if (s[i] != c)
				words++;
		}
		else
		{
			if (s[i] != c && s[i - 1] == c)
				words++;
		}
		i++;
	}
	return (words);
}

static int	ft_len(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		cheat[3];

	if (!s)
		return (NULL);
	cheat[1] = ft_countwords(s, c);
	r = (char **)malloc(sizeof(*r) * (cheat[1] + 1));
	if (!r)
		return (NULL);
	cheat[2] = 0;
	while (cheat[2] < cheat[1])
	{
		while (*s == c)
			s++;
		r[cheat[2]] = (char*)malloc(sizeof(r[cheat[2]]) * ft_len(s, c) + 1);
		if (!r[cheat[2]])
			return (NULL);
		ft_strncpy(r[cheat[2]], s, ft_len(s, c));
		r[cheat[2]][ft_len(s, c)] = '\0';
		s += ft_len(s, c);
		cheat[2]++;
	}
	r[cheat[2]] = NULL;
	return (r);
}
