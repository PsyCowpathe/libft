/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:52:18 by agirona           #+#    #+#             */
/*   Updated: 2021/03/17 18:02:51 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_mlx *data, char *str)
{
	data->mapy = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, str);
	data->img = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	data->addr = mlx_get_data_addr(data->img, &data->bits,
			&data->linelen, &data->endian);
}

void	init_player(t_mlx *data)
{
	int		x;
	int		y;

	y = 0;
	data->fov = 60;
	data->cubesize = 1;
	data->proj = (WIN_X / 2) / tan(30 * (M_PI / 180));
	data->between = data->fov / WIN_X;
	//data->between = floorf(data->between * 100) / 100;
	while (y < data->mapy)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (ft_ischar("NEWS", data->map[y][x]) == 1)
			{
				data->px = x;
				data->py = y;
				data->map[y][x] = '0';
			}
			if (data->map[y][x] == 'E')
				data->pa = 0;
			if (data->map[y][x] == 'N')
				data->pa = 90;
			if (data->map[y][x] == 'W')
				data->pa = 180;
			if (data->map[y][x] == 'S')
				data->pa = 270;
			x++;
		}
		y++;
	}
}
