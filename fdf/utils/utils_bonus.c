/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:33:09 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/15 05:16:52 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	menue(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 10, 10, 0x8A2BE2,
		"Move: Arrows  (-> , <- , up , down)");
	mlx_string_put(data->mlx, data->win, 10, 30, 0x8A2BE2,
		"Zoom: Scroll up, scroll down || + , -");
	mlx_string_put(data->mlx, data->win, 10, 50, 0x8A2BE2,
		"Rotate: z , x , y || c , q , w");
	mlx_string_put(data->mlx, data->win, 10, 70, 0x8A2BE2,
		"Parallel projection: p");
	mlx_string_put(data->mlx, data->win, 10, 90, 0x8A2BE2,
		"isometric projection: i");
	mlx_string_put(data->mlx, data->win, 10, 110, 0x8A2BE2,
		"Reset: r");
	return ;
}

void	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file == NULL)
	{
		ft_error("Error\nFile not found");
		exit(0);
	}
	if (len < 4 || file[len - 1] != 'f' || file[len - 2] != 'd'
		|| file[len - 3] != 'f' || file[len - 4] != '.')
	{
		ft_error("Make sure to use a file with the .fdf extension");
		exit(0);
	}
}

void	function_handler(t_data *data)
{
	center_map(data);
	three_init1(data);
	render_image(data);
	close_final(data);
}

void	center_map(t_data *data)
{
	int	x;
	int	y;

	data->zoom = min_v(WIDTH / (data->columns),
			HEIGHT / (data->rows)) * 0.5 + 1;
	x = (WIDTH - data->columns * data->zoom) / 2;
	y = (HEIGHT - data->rows * data->zoom) / 2;
	data->shift_x = x;
	data->shift_y = y;
}
