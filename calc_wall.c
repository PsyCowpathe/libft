/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:55:10 by agirona           #+#    #+#             */
/*   Updated: 2021/04/13 18:59:39 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_first_hor(t_mlx *data, float rayon)
{
	int		tmp;

	tmp = floor(data->py / data->cubesize);
	if (rayon >= 0 && rayon < 180)
		data->hory = tmp * data->cubesize;
	else if (rayon >= 180 && rayon <= 360)
		data->hory = tmp * data->cubesize + data->cubesize;
	data->horx = data->px + (data->py - data->hory) / tan(rayon * (M_PI / 180));
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
}

float	get_closest_vertical_wall(t_mlx *data, float rayon)
{
	float	nextx;
	float	nexty;
	float	add;
	float	dist;

	nextx = data->vertx;
	nexty = data->verty;
	add = tan(rayon * (M_PI / 180));
	while (nextx >= 0 && nextx <= 18 && nexty >= 0 && nexty <= 6 && data->map[(int)nexty][(int)nextx] == '0')
	{
		if (rayon >= 0 && rayon < 90)
		{
			nextx = nextx + 1;
			nexty = nexty - add;
		}
		else if (rayon >= 90 && rayon < 180)
		{
			nextx = nextx - 1;
			nexty = nexty + add;
			nextx = nextx - 0.01;
		}
		else if (rayon >= 180 && rayon < 270)
		{
			nextx = nextx - 1;
			nexty = nexty + add;
			nextx = nextx - 0.01;
		}
		else if (rayon >= 270 && rayon <= 360)
		{
			nextx = nextx + 1;
			nexty = nexty - add;
		}
	}
	dprintf(1, "VWall x = %f y = %f", nextx, nexty);
	dist = sqrt(pow(nextx - data->px, 2) + pow(nexty - data->py, 2));
	return (dist);
}

float	get_closest_horizontal_wall(t_mlx *data, float rayon)
{
	float	nextx;
	float	nexty;
	float	add;
	float	dist;

	nextx = data->horx;
	nexty = data->hory;
	add = 1 / tan(rayon * (M_PI / 180));
	while (nextx >= 0 && nextx <= 18 && nexty >= 0 && nexty <= 6 && data->map[(int)nexty][(int)nextx] == '0')
	{
		if (rayon >= 0 && rayon < 90)
		{
			nexty = nexty - 1;
			nextx = nextx + add;
			nexty = nexty - 0.01;
		}
		else if (rayon >= 90 && rayon < 180)
		{
			nexty = nexty - 1;
			nextx = nextx + add;
			nexty = nexty - 0.01;
		}
		else if (rayon >= 180 && rayon < 270)
		{
			nexty = nexty + 1;
			nextx = nextx - add;
		}
		else if (rayon >= 270 && rayon <= 360)
		{
			nexty = nexty + 1;
			nextx = nextx - add;
		}
	}
	dprintf(1, " HWall x = %f y = %f", nextx, nexty);
	dist = sqrt(pow(nextx - data->px, 2) + pow(nexty - data->py, 2));
	return (dist);
}

float	get_closest_wall(t_mlx *data, float rayon)
{
	float	vdist;
	float	hdist;

	vdist = get_closest_vertical_wall(data, rayon);
	hdist = get_closest_horizontal_wall(data, rayon);
	dprintf(1, " Hdist = %f Vdist = %f", hdist, vdist);
	if (vdist < hdist)
	{
		ft_putstr("Vertical");
		return (vdist);
	}
	else
	{
		ft_putstr("Horizontal");
		return (hdist);
	}
}

void	calc_distance(t_mlx *data)
{
	float	rayon;
	float	distance;
	float	wallheight;
	int		x;
	char	*tmp;
	float	patch;

	patch = -30;
	rayon = data->pa - (data->fov / 2);
	x = WIN_X - 1;
	while (x >= 0)
	{
		if (rayon < 0)
			rayon = 360 + rayon;
		else if (rayon > 360)
			rayon = 0 + (rayon - 360);
		dprintf(1, "\nangle = %f ", rayon);
		tmp = ft_itoa(rayon);
		free(tmp);
		get_first_hor(data, rayon);
		get_first_vert(data, rayon);
		distance = get_closest_wall(data, rayon);
		distance = distance * cos(patch * (M_PI / 180));
		wallheight = data->cubesize / distance * data->proj;
		print_column(data, x, wallheight / 10);
		rayon = rayon + data->between;
		//dprintf(1, " %f height = %f", patch, wallheight);
		patch += data->between;
		x--;
	}
}
