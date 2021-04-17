/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:53:37 by agirona           #+#    #+#             */
/*   Updated: 2021/04/17 18:42:57 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pixel(t_mlx *data, int x, int y, int color)
{
	data->addr[y * WIN_X + x] = color;
}

void	print_column(t_mlx *data, int x, int height, int wich)
{
	float	i;
	float	between;
	float	y;
	int		tmpx;
	int		tmpy;
	(void)wich;

	i = 0;
	between = (float)64 / (height * 2);
	dprintf(1, "%f", between);
	tmpx = x % 64;
	tmpy = (WIN_Y / 2) + (height / 2);
	y = 0;
	while (i < (height * 2))
	{
		data->addr[(tmpy - (int)i) * WIN_X + x] = data->text_data[(int)y * 64 + tmpx];
		i++;
		//i += between;
		y += between;
	}
}

void	clear_win(t_mlx *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < WIN_Y)
	{
		while (x < WIN_X)
		{
			if (y <= (WIN_Y / 2))
				set_pixel(data, x, y, SKY);
			else
				set_pixel(data, x, y, DIRT);
			x++;
		}
		x = 0;
		y++;
	}
}
