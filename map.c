/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:51:33 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/06 09:30:40 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	getmap(t_info *i)
{
	char	*s;
	int		nb_lignes;
	int		inc;
	int		fd;

	fd = open("start.map", O_RDONLY);
	get_next_line(fd, &s);
	nb_lignes = ft_atoi(s);
	free(s);
	if (!(i->map = (char **)malloc(sizeof(char *) * nb_lignes)))
		return ;
	inc = 0;
	while (inc < nb_lignes)
	{
		get_next_line(fd, &s);
		i->map[inc] = ft_strdup(s);
		free(s);
		inc++;
	}
	close(fd);
}


