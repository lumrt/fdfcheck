/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:58:36 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/22 01:16:03 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	absolute(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	my_pixel_put_img(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	x += OFFX;
	y += OFFY;
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	isometric(int *x, int *y, int z)
{
	int	prevx;
	int	prevy;

	prevx = *x;
	prevy = *y;
	*x = (prevx - prevy) * cos(0.523599);
	*y = -z + (prevx + prevy) * sin(0.523599);
}

void	brasenham(t_point dot1, t_point dot2, t_fdf *data)
{
	int	ex = absolute(dot2.x - dot1.x);
	int	ey = absolute(dot2.y - dot1.y);
	int	dx = 2 * ex;
	int	dy = 2 * ey;
	// int	dxx = ex; 
	// int	dyy = ey;	
	int	i = 0;
	int	Xincr = 1;
	int	Yincr = 1;

	dot1.x *= data->zoom;
	dot1.y *= data->zoom;
	dot2.x *= data->zoom;
	dot2.y *= data->zoom;
	dot1.x += 500;
	dot1.y -= 250;
	dot2.x += 600;
	dot2.y -= 500;
	isometric(&dot1.x, &dot1.y, dot1.z);
	isometric(&dot2.x, &dot2.y, dot2.z);
	//////////////////////////////////////////////// PARAMETERS /////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////
	if (dot1.x > dot2.x)
		Xincr = -1;
	if (dot1.y > dot2.y)
		Yincr = -1;
	if (dx > dy)
	{
		while (i <= dx)
		{
			if (dot1.z != 0)
				data->color = 0xFFF000;
			else
				data->color = 0xFFFFFF;
			my_pixel_put_img(data, dot1.x, dot1.y, data->color);
			// printf("pixel turned on at %d, %d in color %u\n\n", dot1.x, dot1.y, data->color);
			i++;
			dot1.x += Xincr;
			ex -= dy;
			if (ex < 0)
			{
				dot1.y += Yincr;
				ex += dx;
			}
		}
	}
	else
	{
		while (i <= dy)
		{
			if (dot1.z != 0)
				data->color = 0xFFF000;
			else
				data->color = 0xFFFFFF;
			my_pixel_put_img(data, dot1.x, dot1.y, data->color);
			// printf("pixel turned on at %d, %d in color %u\n\n", dot1.x, dot1.y, data->color);
			i++;
			dot1.y += Yincr;
			ey -= dx;
			if (ey < 0)
			{
				dot1.x += Xincr;
				ey += dy;
			}
		}
	}
}

void	draw(t_fdf *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->matrix[y] != NULL)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				brasenham(data->matrix[y][x], data->matrix[y][x + 1], data);
			if (y < data->height - 1)
				brasenham(data->matrix[y][x], data->matrix[y + 1][x], data);
			x++;
		}
		y++;
	}
}
// to delete / fix