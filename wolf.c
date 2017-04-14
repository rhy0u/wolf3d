/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:31:42 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/11 13:04:40 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	initview(t_info *i, int x)
{
	i->camx = 2 * (float)x / WIDTH - 1;
	i->raypos.x = i->pos.x;
	i->raypos.y = i->pos.y;
	i->raydir.x = i->dir.x + i->plane.x * i->camx;
	i->raydir.y = i->dir.y + i->plane.y * i->camx;
	i->mappos.x = (int)i->raypos.x;
	i->mappos.y = (int)i->raypos.y;
	i->deltadist.x = sqrt(1 + (i->raydir.y * i->raydir.y) /
			(i->raydir.x * i->raydir.x));
	i->deltadist.y = sqrt(1 + (i->raydir.x * i->raydir.x) /
			(i->raydir.y * i->raydir.y));
}

void	setsidedist(t_info *i)
{
	if (i->raydir.x < 0)
	{
		i->step.x = -1;
		i->sidedist.x = (i->raypos.x - i->mappos.x) * i->deltadist.x;
	}
	else
	{
		i->step.x = 1;
		i->sidedist.x = (1 + i->mappos.x - i->raypos.x) * i->deltadist.x;
	}
	if (i->raydir.y < 0)
	{
		i->step.y = -1;
		i->sidedist.y = (i->raypos.y - i->mappos.y) * i->deltadist.y;
	}
	else
	{
		i->step.y = 1;
		i->sidedist.y = (1 + i->mappos.y - i->raypos.y) * i->deltadist.y;
	}
}

void	wall(t_info *i)
{
	int		hit;

	hit = 0;
	while (!hit)
	{
		if (i->sidedist.x < i->sidedist.y)
		{
			i->sidedist.x += i->deltadist.x;
			i->mappos.x += i->step.x;
			i->side = 0;
		}
		else
		{
			i->sidedist.y += i->deltadist.y;
			i->mappos.y += i->step.y;
			i->side = 1;
		}
		if (i->map[i->mappos.y][i->mappos.x] - '0')
			hit = 1;
	}
}

void	raytrace(t_info *i)
{
	if (i->side == 0)
		i->perpwalldist = (i->mappos.x - i->raypos.x + (1 - i->step.x) / 2)
			/ i->raydir.x;
	else
		i->perpwalldist = (i->mappos.y - i->raypos.y + (1 - i->step.y) / 2)
			/ i->raydir.y;
	i->lineh = (int)(HEIGHT / i->perpwalldist);
	i->draws = -i->lineh / 2 + HEIGHT / 2;
	if (i->draws < 0)
		i->draws = 0;
	i->drawe = i->lineh / 2 + HEIGHT / 2;
	if (i->draws > HEIGHT)
		i->draws = HEIGHT - 1;
	i->texnum = i->map[i->mappos.y][i->mappos.x] - '1';
	if (!i->side)
		i->wallx = i->raypos.y + i->perpwalldist * i->raydir.y;
	else
		i->wallx = i->raypos.x + i->perpwalldist * i->raydir.x;
}

void	wolf(t_info *i)
{
	int		x;

	x = 0;
	ft_bzero(i->pixels, WIDTH * HEIGHT * sizeof(Uint32));
	while (x < WIDTH)
	{
		initview(i, x);
		setsidedist(i);
		wall(i);
		raytrace(i);
		i->wallx -= (int)i->wallx;
		i->tex.x = (int)(i->wallx * (double)TEXW);
		if (i->side && i->raydir.y < 0)
			i->tex.x = TEXW - i->tex.x - 1;
		if (i->side == 0 && i->raydir.x > 0)
			i->tex.x = TEXW - i->tex.x - 1;
		draw(i, x);
		x++;
	}
}
