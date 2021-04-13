/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:22:57 by agirona           #+#    #+#             */
/*   Updated: 2021/04/13 18:59:36 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map, int max)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < max)
	{
		while (map[y][x])
			ft_putchar(map[y][x++]);
		x = 0;
		ft_putchar('\n');
		y++;
	}
}


void	square(t_mlx *data, int x, int y, int size, int color)
{
	int		i;

	i = 0;
	while (i < size)
	{
		set_pixel(data, x + i, y, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		set_pixel(data, x, y + i, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		set_pixel(data, x + size, y + i, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		set_pixel(data, x + i, y + size, color);
		i++;
	}
}

int		*rotate(int *centerxy, int *pointxy, float angle)
{
	int		*newxy;
	int		tmpx;
	int		tmpy;
	
	newxy = malloc(sizeof(int) * 2);
	angle = angle * -1;
	newxy[0] = pointxy[0] - centerxy[0];
	newxy[1] = pointxy[1] - centerxy[0];
	tmpx = newxy[0] * cos(angle) - newxy[1] * sin(angle);
	tmpy = newxy[0] * sin(angle) + newxy[1] * cos(angle);
	newxy[0] = tmpx + centerxy[0] * 20 + 10;
	newxy[1] = tmpy + centerxy[1] * 20 + 10;
	//tab[0] = centerxy[0] * 20 + 10;
	//tab[1] = centerxy[1] * 20 + 10;
	return (newxy);
}

void	mini_map(t_mlx *data, int size)
{
	int		x;
	int		y;
	int		centerxy[2];
	int		pointxy[2];
	int		*tmp;
	int		*tab;

	y = 0;
	tab = malloc(sizeof(int) * 4);
	while (y <= 6)
	{
		x = 0;
		while (x <= 18)
		{
			if (data->map[y][x] == '1')
				square(data, x * size, y * size, size, WHITE);
			x++;
		}
		y++;
	}
	square(data, (int)data->px * size, (int)data->py * size, size, RED);
	centerxy[0] = data->px;
	centerxy[1] = data->py;
	pointxy[0] = data->px + 50;
	pointxy[1] = data->py;
	tmp = rotate(centerxy, pointxy, (data->pa - 30) * M_PI / 180);
	tab[0] = centerxy[0] * 20 + 10;
	tab[1] = centerxy[1] * 20 + 10;
	tab[2] = tmp[0];
	tab[3] = tmp[1];
	draw_utility(tab, data);
	free(tmp);
	tmp = rotate(centerxy, pointxy, (data->pa + 30) * M_PI / 180);
	tab[0] = centerxy[0] * 20 + 10;
	tab[1] = centerxy[1] * 20 + 10;
	tab[2] = tmp[0];
	tab[3] = tmp[1];
	free(tmp);
	draw_utility(tab, data);
	free(tab);
}

int		keyboard(int key, t_mlx *data)
{
	int		*tmp;
	int		centerxy[2];
	int		pointxy[2];

	clear_win(data);
	if (key == 124 || key == 123)
	{
		if (key == 124)
		{
			data->pa -= ROT;
			if (data->pa < 0)
				data->pa = 360 + data->pa;
		}
		else
		{
			data->pa += ROT;
			if (data->pa > 360)
				data->pa = 0 + (data->pa - 360);
		}
		//dprintf(1, "angle = %f", data->pa);
	}
	else if (key == 13)
	{
		centerxy[0] = data->px;
		centerxy[1] = data->py;
		pointxy[0] = data->px + 1;
		pointxy[1] = data->py;
		tmp = rotate(centerxy, pointxy, data->pa * (M_PI / 180));
		data->px = tmp[0]; 
		data->py = tmp[1]; 
	}
	mini_map(data, 20);
	calc_distance(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc == 2 || (argc == 3 && ft_strcmp(argv[2], "--save") == 0))
	{
		init_mlx(&data, argv[1]);
		if (read_map(argv[1], &data) == 0)
			return (0);
		clear_win(&data);
		init_player(&data);
		data.px = 3.5;
		data.py = 2.5;
		calc_distance(&data);
		mini_map(&data, 20);
		mlx_key_hook(data.win, keyboard, &data);
		mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
		mlx_loop(data.mlx);
	}
	else
		ft_putstr("Usage ./cub3d map.cub || ./cub3d map.cub --save");
	return (1);
}
