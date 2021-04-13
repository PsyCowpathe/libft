/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:29:34 by agirona           #+#    #+#             */
/*   Updated: 2021/04/13 18:59:37 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

# include <stdio.h> //a delete

# define WIN_X 1920
# define WIN_Y 1080
# define RED 0XFF0000
# define BLUE 0X0000FF
# define GREEN 0X00FF00
# define WHITE 0XFFFFFF
# define DIRT 0XB68831
# define SKY 0X87CEFA
# define ROT 3

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits;
	int		linelen;
	int		endian;

	char	**map;
	int		mapy;
	float	px;
	float	py;
	float	pa;
	float	fov;
	float	dir;
	float	between;
	int		cubesize;
	int		proj;

	float	vertx;
	float	verty;
	float	horx;
	float	hory;
	float	nexthorx;
	float	nexthory;
	float	nextvertx;
	float	nextverty;
}				t_mlx;


void	init_mlx(t_mlx *data, char *str);
void	init_player(t_mlx *data);

int	read_map(char *str, t_mlx *data);

int		*rotate(int *centerxy, int *pointxy, float angle);


void	set_pixel(t_mlx *data, int x, int y, int color);
void	clear_win(t_mlx *data);
void	print_column(t_mlx *data, int x, int height);

void	calc_distance(t_mlx *data);


void	draw_utility(int *tab, t_mlx *data);

#endif
