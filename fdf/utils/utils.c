/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:32:22 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/15 03:49:45 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_putendl_fd(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	while (*str)
		write(fd, str++, 1);
	write(fd, "\n", 1);
}

void	ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

void	check_file1(char *file)
{
	int	len;

	(file == NULL)
		&& (ft_error("Error\nFile not found"), exit(0), 0);
	len = ft_strlen(file);
	(len < 4 || file[len - 1] != 'f' || file[len - 2] != 'd'
		|| file[len - 3] != 'f' || file[len - 4] != '.')
		&& (ft_error("Make sure to use a file with the .fdf extension")
		, exit(1), 0);
}

void	function_handler1(t_data *data)
{
	center_map1(data);
	three_init(data);
	render_image1(data);
	close_final(data);
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
