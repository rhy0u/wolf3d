/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:56:42 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/12 01:21:20 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	up(t_info *i)
{
	if (i->map[(int)(i->pos.y)]
			[(int)(i->pos.x + i->movespeed * i->dir.x)] <= '0')
		i->pos.x += i->movespeed * i->dir.x;
	if (i->map[(int)(i->pos.y + i->movespeed * i->dir.y)]
			[(int)(i->pos.x)] <= '0')
		i->pos.y += i->movespeed * i->dir.y;
}

void	down(t_info *i)
{
	if (i->map[(int)(i->pos.y)]
			[(int)(i->pos.x - i->movespeed * i->dir.x)] <= '0')
		i->pos.x -= i->movespeed * i->dir.x;
	if (i->map[(int)(i->pos.y - i->movespeed * i->dir.y)]
			[(int)(i->pos.x)] <= '0')
		i->pos.y -= i->movespeed * i->dir.y;
}

void	left(t_info *i, t_coord olddir, t_coord oldplane)
{
	i->dir.x = olddir.x * cos(i->rotspeed) - olddir.y * sin(i->rotspeed);
	i->dir.y = olddir.x * sin(i->rotspeed) + olddir.y * cos(i->rotspeed);
	i->plane.x = oldplane.x * cos(i->rotspeed) - oldplane.y * sin(i->rotspeed);
	i->plane.y = oldplane.x * sin(i->rotspeed) + oldplane.y * cos(i->rotspeed);
}

void	right(t_info *i, t_coord olddir, t_coord oldplane)
{
	i->dir.x = olddir.x * cos(-i->rotspeed) - olddir.y * sin(-i->rotspeed);
	i->dir.y = olddir.x * sin(-i->rotspeed) + olddir.y * cos(-i->rotspeed);
	i->plane.x = oldplane.x * cos(-i->rotspeed)
		- oldplane.y * sin(-i->rotspeed);
	i->plane.y = oldplane.x * sin(-i->rotspeed)
		+ oldplane.y * cos(-i->rotspeed);
}

void	readkeys(t_info *i)
{
	t_coord	olddir;
	t_coord	oldplane;
	int		key;

	key = i->event.key.keysym.sym;
	olddir.x = i->dir.x;
	olddir.y = i->dir.y;
	oldplane.x = i->plane.x;
	oldplane.y = i->plane.y;
	if (key == SDLK_w || key == SDLK_UP)
		up(i);
	else if (key == SDLK_s || key == SDLK_DOWN)
		down(i);
	else if (key == SDLK_a || key == SDLK_LEFT)
		left(i, olddir, oldplane);
	else if (key == SDLK_d || key == SDLK_RIGHT)
		right(i, olddir, oldplane);
	else if (i->event.key.keysym.sym == SDLK_f)
		SDL_SetWindowFullscreen(i->win, SDL_WINDOW_FULLSCREEN);
	else if (i->event.key.keysym.sym == SDLK_g)
		SDL_SetWindowFullscreen(i->win, SDL_WINDOW_FULLSCREEN_DESKTOP);
	else if (i->event.key.keysym.sym == SDLK_h)
		SDL_SetWindowFullscreen(i->win, 0);
	else if (i->event.key.keysym.sym == SDLK_ESCAPE)
		i->running = 0;
}
