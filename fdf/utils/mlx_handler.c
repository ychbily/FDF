/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:10:10 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/14 23:05:59 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	mlx_handler(t_data *data)
{
	data->mlx = mlx_init();
	(!data->mlx) && (ft_error("Failed to initialize connection!"), 0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fdf");
	(!data->win) && (ft_error("Failed to create new window!"), 0);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	(!data->img.img) && (mlx_destroy_window(data->mlx, data->win)
		, ft_error("Failed to create new image!"), 0);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	(!data->img.addr) && (ft_error("Failed to get image data!")
		, handle_close(data), 0);
}
