/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:51:33 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/13 22:55:35 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	getmap(t_info *i)
{
	char	*s;
	int		inc;
	int		fd;

	fd = open("./map/start.map", O_RDONLY);
	get_next_line(fd, &s);
	i->nb_lignes = ft_atoi(s);
	free(s);
	if (!(i->map = (char **)malloc(sizeof(char *) * i->nb_lignes)))
		return ;
	inc = 0;
	while (inc < i->nb_lignes)
	{
		get_next_line(fd, &s);
		if (!(i->map[inc] = malloc(strlen(s) + 1)))
			return ;
		ft_strcpy(i->map[inc], s);
		ft_strdel(&s);
		inc++;
	}
	close(fd);
}

void	freemap(t_info *i)
{
	int		inc;

	inc = 0;
	while (inc < i->nb_lignes)
	{
		free(i->map[inc]);
		inc++;
	}
	free(i->map);
}
