/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:08:48 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/06 10:01:33 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

Uint32	rgbtouint(int r, int g, int b)
{
	return (((256 + r) * 256 + g) * 256 + b);
}

void	uinttorgb(int *r, int *g, int *b, Uint32 i)
{
	*b = i & 255;
	*g = i >> 8 & 255;
	*r = i >> 16 & 255;
}

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return *p;
	else if (bpp == 2)
		return *(Uint16 *)p;
	else if (bpp == 3)
	{
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
	}
	else if (bpp == 4)
		return *(Uint32 *)p;
	else
		return 0;
}

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
	int		y;
	int		r, g , b;
	Uint32		pixel;

	floorcast(i);
	y = i->drawe + 1;
	while (y < HEIGHT)
	{
		i->currentdist = (double)(HEIGHT / ( 2.0 * y - HEIGHT));
		i->weight = (i->currentdist - i->distplayer)
			/ (i->distwall - i->distplayer);
		i->currentfloor.x = i->weight * i->floorwall.x
			+ (1.0 - i->weight) * i->pos.x;
		i->currentfloor.y = i->weight * i->floorwall.y
			+ (1.0 - i->weight) * i->pos.y;
		i->floortex.x = (int)(i->currentfloor.x * 32) % 32;
		i->floortex.y = (int)(i->currentfloor.y * 32) % 32;
		pixel = getpixel(i->textures[8], i->floortex.y, i->floortex.x);
		uinttorgb(&r, &g, &b, pixel);
		i->pixels[y * WIDTH + x] = rgbtouint(r / 2, g / 2, b / 2);
		i->pixels[(HEIGHT - y) * WIDTH + x] = rgbtouint(r, g, b);
		y++;
	}
}

void	draw(t_info *i, int x)
{
	int		d;
	int		r, g , b;
	Uint32		pixel;
	int			y;

	y = i->draws;
	if (i->drawe > HEIGHT)
		i->drawe = HEIGHT - 1;
	if (i->draws < 0)
		i->draws = 0;
	while (y < i->drawe)
	{
		d = y * 256 - HEIGHT * 128 + i->lineh * 128;
		i->tex.y = ((d * TEXH) / i->lineh )/ 256;
		pixel = getpixel(i->textures[i->texnum], i->tex.x, i->tex.y);
		uinttorgb(&r, &g, &b, pixel);
		if(!i->side)
			i->pixels[y * WIDTH + x] = rgbtouint(r, g, b);
		else
			i->pixels[y * WIDTH + x] = rgbtouint(r / 2, g / 2, b / 2);
		y++;
	}
	drawfloorsky(i, x);
}
