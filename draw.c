/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:53:37 by agirona           #+#    #+#             */
/*   Updated: 2021/04/12 16:08:54 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pixel(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->linelen + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}

void	print_column(t_mlx *data, int x, int height)
{
	int		i;

	i = 0;
	if (height > (WIN_Y / 2))
		height = WIN_Y / 2;
	while (i < height)
	{
		set_pixel(data, x, (WIN_Y / 2) - i, WHITE);
		i++;
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
