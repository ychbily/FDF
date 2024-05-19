/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:45:57 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/17 20:33:07 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_image(t_data *data)
{
	ft_bzero(data->img.addr, HEIGHT * WIDTH * (data->img.bits_per_pixel / 8));
	dda_draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	menue(data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->img.addr
		+ (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	three_init1(t_data *data)
{
	data->x_teta = -0.366;
	data->y_teta = -0.236;
	data->z_teta = 0.0;
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac == 2)
	{
		check_file(av[1]);
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		map(data, av[1]);
		mlx_handler(data);
		function_handler(data);
		mlx_hook(data->win, 4, 0, mouse_press, data);
		mlx_hook(data->win, 2, 0, move, data);
		mlx_loop(data->mlx);
	}
	else
		ft_error("Error\nUsage: ./fdf <filename>");
	return (0);
}
