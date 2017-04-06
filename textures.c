/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:48:26 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/06 10:00:33 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	inittex(t_info *i)
{
	i->textures[0] = SDL_LoadBMP("tex/tex0.bmp");
	if (!i->textures[0])printf("tex\n");
	i->textures[1] = SDL_LoadBMP("tex/tex1.bmp");
	if (!i->textures[1])printf("tex\n");
	i->textures[2] = SDL_LoadBMP("tex/tex2.bmp");
	if (!i->textures[2])printf("tex\n");
	i->textures[3] = SDL_LoadBMP("tex/tex3.bmp");
	if (!i->textures[3])printf("tex\n");
	i->textures[4] = SDL_LoadBMP("tex/tex4.bmp");
	if (!i->textures[4])printf("tex\n");
	i->textures[5] = SDL_LoadBMP("tex/tex5.bmp");
	if (!i->textures[5])printf("tex\n");
	i->textures[6] = SDL_LoadBMP("tex/tex6.bmp");
	if (!i->textures[6])printf("tex\n");
	i->textures[7] = SDL_LoadBMP("tex/tex7.bmp");
	if (!i->textures[7])printf("tex\n");
}

void	freetex(t_info *i)
{
	SDL_FreeSurface(i->textures[0]);
	SDL_FreeSurface(i->textures[1]);
	SDL_FreeSurface(i->textures[2]);
	SDL_FreeSurface(i->textures[3]);
	SDL_FreeSurface(i->textures[4]);
	SDL_FreeSurface(i->textures[5]);
	SDL_FreeSurface(i->textures[6]);
	SDL_FreeSurface(i->textures[7]);
}
