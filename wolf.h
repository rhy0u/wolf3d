/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:02:25 by jcentaur          #+#    #+#             */
/*   Updated: 2017/04/13 18:39:15 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <math.h>
# include <sdl2/SDL.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# define HEIGHT 720
# define WIDTH 1280
# define TEXW 64
# define TEXH 64

typedef struct			s_coord
{
	double				x;
	double				y;
}						t_coord;

typedef struct			s_int
{
	int					x;
	int					y;
}						t_int;

typedef struct			s_info
{
	SDL_Window			*win;
	SDL_Renderer		*ren;
	SDL_Event			event;
	SDL_Texture			*img;
	SDL_Surface			*textures[9];
	SDL_GameController	*gpd;
	t_coord				pos;
	t_coord				dir;
	t_coord				plane;
	t_coord				raypos;
	t_coord				raydir;
	t_coord				sidedist;
	t_coord				deltadist;
	t_coord				floorwall;
	t_coord				currentfloor;
	double				distwall;
	double				weight;
	double				currentdist;
	double				distplayer;
	double				wallx;
	double				perpwalldist;
	double				camx;
	double				frametime;
	double				movespeed;
	double				rotspeed;
	t_int				step;
	t_int				mappos;
	t_int				tex;
	t_int				floortex;
	int					running;
	int					hit;
	int					side;
	int					lineh;
	int					draws;
	int					drawe;
	int					texnum;
	int					fs;
	int					gpdpress;
	int					nb_lignes;
	Uint32				*pixels;
	Uint32				time;
	Uint32				time_old;
	Uint32				color;
	char				**map;
}						t_info;

void					map1(char ***map);
void					wolf(t_info *i);
void					readkeys(t_info *i);
void					getmap(t_info *i);
void					draw(t_info *i, int x);
void					inittex(t_info *i);
void					freetex(t_info *i);
void					floorcast(t_info *i);
void					controllerevent(t_info *i);
Uint32					rgbtoi(int r, int g, int b);
void					uinttorgb(int *r, int *g, int *b, Uint32 i);
Uint32					getpixel(SDL_Surface *surface, int x, int y);
void					freemap(t_info *i);

#endif
