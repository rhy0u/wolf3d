/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamepad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 00:48:04 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/12 01:16:13 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	up(t_info *i)
{
	if (i->map[(int)(i->pos.y)]
			[(int)(i->pos.x + i->movespeed * i->dir.x)] <= '0')
		i->pos.x += i->movespeed * i->dir.x;
	if (i->map[(int)(i->pos.y + i->movespeed * i->dir.y)]
			[(int)(i->pos.x)] <= '0')
		i->pos.y += i->movespeed * i->dir.y;
}

static void	down(t_info *i)
{
	if (i->map[(int)(i->pos.y)]
			[(int)(i->pos.x - i->movespeed * i->dir.x)] <= '0')
		i->pos.x -= i->movespeed * i->dir.x;
	if (i->map[(int)(i->pos.y - i->movespeed * i->dir.y)]
			[(int)(i->pos.x)] <= '0')
		i->pos.y -= i->movespeed * i->dir.y;
}

static void	left(t_info *i, t_coord olddir, t_coord oldplane)
{
	i->dir.x = olddir.x * cos(i->rotspeed) - olddir.y * sin(i->rotspeed);
	i->dir.y = olddir.x * sin(i->rotspeed) + olddir.y * cos(i->rotspeed);
	i->plane.x = oldplane.x * cos(i->rotspeed) - oldplane.y * sin(i->rotspeed);
	i->plane.y = oldplane.x * sin(i->rotspeed) + oldplane.y * cos(i->rotspeed);
}

static void	right(t_info *i, t_coord olddir, t_coord oldplane)
{
	i->dir.x = olddir.x * cos(-i->rotspeed) - olddir.y * sin(-i->rotspeed);
	i->dir.y = olddir.x * sin(-i->rotspeed) + olddir.y * cos(-i->rotspeed);
	i->plane.x = oldplane.x * cos(-i->rotspeed)
		- oldplane.y * sin(-i->rotspeed);
	i->plane.y = oldplane.x * sin(-i->rotspeed)
		+ oldplane.y * cos(-i->rotspeed);
}

void		controllerevent(t_info *i)
{
	t_coord	olddir;
	t_coord	oldplane;
	int		btn;

	olddir.x = i->dir.x;
	olddir.y = i->dir.y;
	oldplane.x = i->plane.x;
	oldplane.y = i->plane.y;
	btn = i->event.cbutton.button;
	if (btn == SDL_CONTROLLER_BUTTON_DPAD_UP)
		up(i);
	else if (btn == SDL_CONTROLLER_BUTTON_DPAD_DOWN)
		down(i);
	else if (btn == SDL_CONTROLLER_BUTTON_DPAD_LEFT)
		left(i, olddir, oldplane);
	else if (btn == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
		right(i, olddir, oldplane);
}
