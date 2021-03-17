/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:55:10 by agirona           #+#    #+#             */
/*   Updated: 2021/03/17 18:02:53 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_first_hor(t_mlx *data, float rayon)
{
	int		tmp;

	tmp = floor(data->py / data->cubesize);
	if (rayon > 0 && rayon < 180)
		data->hory = tmp * data->cubesize;
	else if (rayon > 180 && rayon < 360)
		data->hory = tmp * data->cubesize + data->cubesize;
	data->horx = data->px + (data->py - data->hory) / tan(rayon * (M_PI / 180));
	//dprintf(1, "\nLa premiere intersection horizontale se trouve en x = %f y = %f\n", data->horx, data->hory);
}

void	get_first_vert(t_mlx *data, float rayon)
{
	int		tmp;

	tmp = floor(data->px / data->cubesize);
	if ((rayon > 0 && rayon < 90) || (rayon > 270 && rayon < 360))
		data->vertx = tmp * data->cubesize + data->cubesize;
	else
		data->vertx = tmp * data->cubesize;
	data->verty = data->py + (data->px - data->vertx) * tan(rayon * (M_PI / 180));
	//dprintf(1, "\nLa premiere intersection verticale se trouve en x = %f y = %f", data->vertx, data->verty);
}

float	get_closest_wall(t_mlx *data, float rayon)
{
	int		x;
	int		y;
	float	addx;
	float	addy;
	float	nextx;
	float	nexty;
	float	hdist;
	float	vdist;

	x = (int)data->horx;
	y = (int)data->hory;
	nextx = data->horx;
	nexty = data->hory;
	addy = 1;
	addx = data->cubesize / tan(rayon * (M_PI / 180));
	ft_putstr("coucou");	
	while (x >= 0 && x < 7 && y >= 0 && y < 18 && data->map[y][x] == '0')
	{
		if (rayon >= 0 && rayon < 180)
			nexty = nexty - addy;
		else
			nexty = nexty + addy;
		nextx = nextx + addx;
		x = (int)(nextx);
		y = (int)(nexty) - 1;
		dprintf(1, "\n x = %d y = %d", x, y);
		//dprintf(1, "\nhorizontal x = %f y = %f", nextx, nexty);
	}
	hdist = sqrt(pow(nextx - data->px, 2) + pow(nexty - data->py, 2));
	//dprintf(1, "\nMur horizontal trouve en x = %f y = %f", nextx, nexty);
	//dprintf(1, "distance horizontal = %f\n", hdist);
	//
	x = (int)data->vertx;
	y = (int)data->verty;
	ft_putstr("parici");
	nextx = data->vertx;
	nexty = data->verty;
	addy = data->cubesize * tan(rayon * (M_PI / 180));
	addx = 1;
	while (x >= 0 && x < 7 && y >= 0 && y < 18 && data->map[y][x] == '0')
	{
		if (rayon >= 0 && rayon <= 90)
			nextx = nextx + addx;
		else
			nextx = nextx - addx;
		nexty = nexty - addy;
		x = (int)nextx - 1;
		y = (int)nexty;
		//dprintf(1, "\nvertical x = %f y = %f", nextx, nexty);
	}
	//dprintf(1, "\nMur vertical trouve en x = %f y = %f", nextx, nexty);
	vdist = sqrt(pow(nextx - data->px, 2) + pow(nexty - data->py, 2));
	//dprintf(1, "\nVdist = %f Hdist = %f ", vdist, hdist);
	ft_putstr("lalala");
	if (vdist < hdist && vdist >= 0)
	{
		//ft_putstr("vertical");
		return (vdist);
	}
	else
	{
		//ft_putstr("horizontal");
		return (hdist);
	}
}

void	calc_distance(t_mlx *data)
{
	float	rayon;
	float	distance;
	int		wallheight;
	int		x;

	rayon = data->pa - (data->fov / 2);
	x = WIN_X - 1;
	while (x >= 0)
	{
		ft_putstr("oui");
		//dprintf(1, "\nangle = %f ", rayon);
		get_first_hor(data, rayon);
		ft_putstr("non1");
		get_first_vert(data, rayon);
		ft_putstr("non2");
		distance = get_closest_wall(data, rayon);
		ft_putstr("non3");
		wallheight = (data->cubesize / distance) * data->proj;
		ft_putstr("non4");
		print_column(data, x, wallheight / 10);
		ft_putstr("non5");
		rayon = rayon + data->between;
		ft_putstr("non6");
		x--;
	}
}
