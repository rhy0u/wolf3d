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
	
	Uint8 *p = (Uint8 *)surface->pixels + x * surface->pitch + y * bpp;
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

void	drawsky(t_info *i)
{
	t_int	pos;

	pos.y = 0;
	while (pos.y < HEIGHT / 2)
	{
		pos.x = 0;
		while (pos.x < WIDTH)
		{
			i->pixels[pos.y * WIDTH + pos.x] = 0x00007F;
			pos.x++;
		}
		pos.y++;
	}
}

void	drawfloor(t_info *i)
{
	t_int	pos;

	pos.y = HEIGHT / 2;
	while (pos.y < HEIGHT)
	{
		pos.x = 0;
		while (pos.x < WIDTH)
		{
			i->pixels[pos.y * WIDTH + pos.x] = 0xFF007F00;
			pos.x++;
		}
		pos.y++;
	}
}

void	floorcast(t_info *i)
{
	if ((!i->side) && (i->raypos.x > 0))
	{
		i->floorwall.x = i->mappos.x;
		i->floorwall.y = i->mappos.y + i->wallx;
	}
	if ((!i->side) && (i->raypos.x < 0))
	{
		i->floorwall.x = i->mappos.x + 1;
		i->floorwall.y = i->mappos.y + i->wallx;
	}
	if ((i->side) && (i->raypos.y > 0))
	{
		i->floorwall.y = i->mappos.y;
		i->floorwall.x = i->mappos.x + i->wallx;
	}
	else
	{
		i->floorwall.y = i->mappos.y + 1;
		i->floorwall.x = i->mappos.x + i->wallx;
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
		if (!i->side)
			i->pixels[y * WIDTH + x] = rgbtouint(r, g, b);
		else
			i->pixels[y * WIDTH + x] = rgbtouint(r / 2, g / 2, b / 2);
		y++;
	}
}
