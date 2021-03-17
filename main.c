/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:22:57 by agirona           #+#    #+#             */
/*   Updated: 2021/03/17 18:02:51 by agirona          ###   ########lyon.fr   */
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

int		keyboard(int key, t_mlx *data)
{
	float	moovx;
	float	moovy;
	(void)data;
	clear_win(data);
	moovx = cos(data->pa) * 2;
	moovy = sin(data->pa) * 2;
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
	if (key == 13)
	{
		data->px = moovx;
		data->py = moovy;
	}
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
		calc_distance(&data);
		mlx_key_hook(data.win, keyboard, &data);
		mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
		mlx_loop(data.mlx);
	}
	else
		ft_putstr("Usage ./cub3d map.cub || ./cub3d map.cub --save");
	return (1);
}
