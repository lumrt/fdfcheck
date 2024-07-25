/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:05:19 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/22 00:25:01 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_key(int key)
{
	printf("%d", key);
	return (key);
}

int	main(int ac, char **av)
{
	t_fdf	*data;
	int		i;
	int		j;

	if (ac != 2)
	{
		printf("./fdf testmaps/map.fdf (to delete it used the stdio printf)");
		exit (1);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->mlx_ptr = mlx_init();
	read_file(av[1], data);
	//////////////////////DEBUG/////////////////////////
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->matrix[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->matrix[i][j].x);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->matrix[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
	////////////////////////////////////////////////////
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FdF");
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->zoom = 20;
	draw(data);
	// t_point dot1 = {12, 1, 0};
	// t_point dot2 = {5, 17, 0};
	// brasenham(dot1, dot2, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	// mlx_key_hook(data->win_ptr, get_key, NULL);
	// mlx_destroy_display(data->mlx_ptr);
	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop(data->mlx_ptr);
}
