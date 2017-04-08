/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:56:42 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/06 09:48:39 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	readkeys(t_info *i)
{
	t_coord	olddir;
	t_coord	oldplane;
	olddir.x = i->dir.x;
	olddir.y = i->dir.y;
	oldplane.x = i->plane.x;
	oldplane.y = i->plane.y;
	if (i->event.key.keysym.sym == SDLK_w || i->event.key.keysym.sym == SDLK_UP)
	{
		if (i->map[(int)(i->pos.y)][(int)(i->pos.x + i->movespeed * i->dir.x)] <= '0')
			i->pos.x += i->movespeed * i->dir.x;
		if (i->map[(int)(i->pos.y + i->movespeed * i->dir.y)][(int)(i->pos.x)] <= '0')
			i->pos.y += i->movespeed * i->dir.y;
	}
	else if (i->event.key.keysym.sym == SDLK_s || i->event.key.keysym.sym == SDLK_DOWN)
	{
		if (i->map[(int)(i->pos.y)][(int)(i->pos.x - i->movespeed * i->dir.x)] <= '0')
			i->pos.x -= i->movespeed * i->dir.x;
		if (i->map[(int)(i->pos.y - i->movespeed * i->dir.y)][(int)(i->pos.x)] <= '0')
			i->pos.y -= i->movespeed * i->dir.y;
	}
	else if (i->event.key.keysym.sym == SDLK_a || i->event.key.keysym.sym == SDLK_LEFT)
	{
		i->dir.x = olddir.x * cos(i->rotspeed) - olddir.y * sin(i->rotspeed);
		i->dir.y = olddir.x * sin(i->rotspeed) + olddir.y * cos(i->rotspeed);
		i->plane.x = oldplane.x * cos(i->rotspeed) - oldplane.y * sin(i->rotspeed);
		i->plane.y = oldplane.x * sin(i->rotspeed) + oldplane.y * cos(i->rotspeed);
	}
	else if (i->event.key.keysym.sym == SDLK_d || i->event.key.keysym.sym == SDLK_RIGHT)
	{
		i->dir.x = olddir.x * cos(-i->rotspeed) - olddir.y * sin(-i->rotspeed);
		i->dir.y = olddir.x * sin(-i->rotspeed) + olddir.y * cos(-i->rotspeed);
		i->plane.x = oldplane.x * cos(-i->rotspeed) - oldplane.y * sin(-i->rotspeed);
		i->plane.y = oldplane.x * sin(-i->rotspeed) + oldplane.y * cos(-i->rotspeed);
	}
	else if (i->event.key.keysym.sym == SDLK_f)
		SDL_SetWindowFullscreen(i->win, SDL_WINDOW_FULLSCREEN);
	else if (i->event.key.keysym.sym == SDLK_g)
		SDL_SetWindowFullscreen(i->win, SDL_WINDOW_FULLSCREEN_DESKTOP);
	else if (i->event.key.keysym.sym == SDLK_h)
		SDL_SetWindowFullscreen(i->win, 0);
	else if (i->event.key.keysym.sym ==	SDLK_ESCAPE)
		i->running = 0;
}
