/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:08:48 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/11 13:43:58 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	floorcast(t_info *i)
{
	if (i->side == 0 && i->raydir.x > 0)
	{
		i->floorwall.x = i->mappos.x;
		i->floorwall.y = i->mappos.y + i->wallx;
	}
	else if (i->side == 0 && i->raydir.x < 0)
	{
		i->floorwall.x = i->mappos.x + 1;
		i->floorwall.y = i->mappos.y + i->wallx;
	}
	else if (i->side == 1 && i->raydir.y > 0)
	{
		i->floorwall.x = i->mappos.x + i->wallx;
		i->floorwall.y = i->mappos.y;
	}
	else
	{
		i->floorwall.x = i->mappos.x + i->wallx;
		i->floorwall.y = i->mappos.y + 1;
	}
	i->distwall = i->perpwalldist;
	i->distplayer = 0.0;
}

void	drawfloorsky(t_info *i, int x)
{
	int			y;
	int			rgb[3];
	Uint32		pixel;

	floorcast(i);
	y = i->drawe;
	while (y < HEIGHT)
	{
		i->currentdist = (double)(HEIGHT / (2.0 * y - HEIGHT));
		i->weight = (i->currentdist - i->distplayer)
			/ (i->distwall - i->distplayer);
		i->currentfloor.x = i->weight * i->floorwall.x
			+ (1.0 - i->weight) * i->pos.x;
		i->currentfloor.y = i->weight * i->floorwall.y
			+ (1.0 - i->weight) * i->pos.y;
		i->floortex.x = (int)(i->currentfloor.x * 32) % 32;
		i->floortex.y = (int)(i->currentfloor.y * 32) % 32;
		pixel = getpixel(i->textures[8], i->floortex.y, i->floortex.x);
		uinttorgb(&rgb[0], &rgb[1], &rgb[2], pixel);
		i->pixels[y * WIDTH + x] = rgbtoi(rgb[0] / 2, rgb[1] / 2, rgb[2] / 2);
		i->pixels[(HEIGHT - y) * WIDTH + x] = rgbtoi(rgb[0], rgb[1], rgb[2]);
		y++;
	}
}

void	draw(t_info *i, int x)
{
	int		d;
	int		rgb[3];
	int		y;

	y = i->draws;
	if (i->drawe > HEIGHT)
		i->drawe = HEIGHT - 1;
	if (i->draws < 0)
		i->draws = 0;
	while (y < i->drawe)
	{
		d = y * 256 - HEIGHT * 128 + i->lineh * 128;
		i->tex.y = ((d * TEXH) / i->lineh) / 256;
		uinttorgb(&rgb[0], &rgb[1], &rgb[2],
			getpixel(i->textures[i->texnum], i->tex.x, i->tex.y));
		if (!i->side)
			i->pixels[y * WIDTH + x] = rgbtoi(rgb[0], rgb[1], rgb[2]);
		else
			i->pixels[y * WIDTH + x] = rgbtoi(rgb[0] / 2, rgb[1] / 2,
				rgb[2] / 2);
		y++;
	}
	drawfloorsky(i, x);
}
