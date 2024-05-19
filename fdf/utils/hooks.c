/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:18:46 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/15 04:03:25 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	three_init(t_data *data)
{
	data->x_teta = -0.666000;
	data->y_teta = 0.514000;
	data->z_teta = 0.550000;
}

void	center_map1(t_data *data)
{
	int	x;
	int	y;

	data->zoom = min_v(WIDTH / (data->columns),
			HEIGHT / (data->rows)) * 0.45;
	if (data->columns > 250)
		data->zoom = data->zoom + 1;
	x = (WIDTH - data->columns * data->zoom) / 2;
	y = (HEIGHT - data->rows * data->zoom) / 2;
	data->shift_x = x - 800;
	data->shift_y = y + 800;
}

void	move_rotation(int key, t_data *data)
{
	(key == 7) && (data->x_teta += 0.05);
	(key == 12) && (data->x_teta -= 0.05);
	(key == 6) && (data->z_teta += 0.05);
	(key == 8) && (data->z_teta -= 0.05);
	(key == 16) && (data->y_teta += 0.05);
	(key == 13) && (data->y_teta -= 0.05);
	(key == 34) && (three_init(data), center_map1(data), 0);
	(key == 35) && (center_map(data), parralel_init(data), 0);
	(key == 15) && (center_map(data), three_init1(data), 0);
}

int	move(int key, t_data *data)
{
	(key == 126) && (data->shift_y -= 10);
	(key == 125) && (data->shift_y += 10);
	(key == 123) && (data->shift_x -= 10);
	(key == 124) && (data->shift_x += 10);
	(key == 69) && (data->zoom += 1);
	(key == 78) && (data->zoom > 1) && (data->zoom -= 1);
	move_rotation(key, data);
	render_image(data);
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom += 1;
	if (button == 5)
		if (data->zoom > 1)
			data->zoom -= 1;
	render_image(data);
	return (0);
}
