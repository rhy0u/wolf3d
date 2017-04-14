/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:02:45 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/14 02:24:28 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		init(t_info *i)
{
	i->pos.x = 4.5;
	i->pos.y = 2.5;
	i->dir.x = -1;
	i->dir.y = 0;
	i->plane.x = 0;
	i->plane.y = 0.66;
	i->running = 1;
	i->time = 0;
	i->time_old = 0;
	i->fs = 0;
	i->gpd = SDL_GameControllerOpen(0);
	if (i->gpd)
		SDL_GameControllerAddMappingsFromFile("gamecontrollerdb.txt");
	getmap(i);
	inittex(i);
	SDL_SetRenderDrawColor(i->ren, 0, 0, 0, 255);
	return (1);
}

void	mainloop(t_info *i)
{
	while (i->running)
	{
		while (SDL_PollEvent(&i->event))
		{
			if (i->event.type == SDL_QUIT)
				controllerevent(i);
			else if (i->event.type == SDL_KEYDOWN)
				readkeys(i);
			//else if (i->event.type == SDL_CONTROLLERBUTTONDOWN)
			//	controllerevent(i);
			readkeys(i);
		}
		i->time_old = i->time;
		i->time = SDL_GetTicks();
		i->frametime = (double)(i->time - i->time_old) / 1000;
		if (16 - i->frametime * 1000 > 0)
			SDL_Delay(16 - i->frametime * 1000);
		wolf(i);
		i->movespeed = i->frametime * 10;
		i->rotspeed = i->frametime * 3.5;
		SDL_UpdateTexture(i->img, NULL, i->pixels, WIDTH * sizeof(Uint32));
		SDL_RenderClear(i->ren);
		SDL_RenderCopy(i->ren, i->img, NULL, NULL);
		SDL_RenderPresent(i->ren);
	}
}

int		main(void)
{
	t_info	i;

	if (!(i.pixels = (Uint32 *)malloc(sizeof(Uint32) * HEIGHT * WIDTH)))
		return (0);
	ft_bzero(i.pixels, WIDTH * HEIGHT * sizeof(Uint32));
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) == -1)
		return (0);
	init(&i);
	i.win = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	i.ren = SDL_CreateRenderer(i.win, -1, 0);
	i.img = SDL_CreateTexture(i.ren, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
	mainloop(&i);
	free(i.pixels);
	if (i.gpd)
		SDL_GameControllerClose(i.gpd);
	SDL_DestroyTexture(i.img);
	SDL_DestroyWindow(i.win);
	freetex(&i);
	freemap(&i);
	SDL_Quit();
	return (0);
}
