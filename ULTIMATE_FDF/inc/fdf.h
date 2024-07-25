/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:46:18 by lucas             #+#    #+#             */
/*   Updated: 2024/07/21 19:15:13 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../src/get_next_line.h"
# include <stdio.h>
# define WIDTH 1280
# define HEIGHT 720
# define OFFX 0
# define OFFY 0

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_fdf
{
	int	width;
	int	height;
	t_point	**matrix;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	zoom;
	unsigned int	color;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	my_pixel_put_img(t_fdf *win_ptr, int x, int y, int color);
int		get_key(int key);
int		ft_count(char *str, char characters);
void	read_file(char *map_name, t_fdf *data);
float	max_of(float a, float b);
void	brasenham(t_point dot1, t_point dot2, t_fdf *data);
void	draw(t_fdf *data);

#endif
