/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:30:33 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/17 20:27:14 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	dda_h(t_dda *dda, t_line *line)
{
	dda->dx = line->x2 - line->x1;
	dda->dy = line->y2 - line->y1;
	if (v_abs(dda->dx) > v_abs(dda->dy))
		dda->steps = v_abs(dda->dx);
	else
		dda->steps = v_abs(dda->dy);
	if (dda->steps != 0)
	{
		dda->xinc = dda->dx / dda->steps;
		dda->yinc = dda->dy / dda->steps;
	}
	else
	{
		dda->xinc = 0;
		dda->yinc = 0;
	}
}

void	dda_algo(t_line *line, t_data *data)
{
	int			i;
	t_dda		dda;
	t_zcolor	zc;

	zc.z = data->map[(int)line->y1][(int)line->x1];
	zc.color1 = data->color[(int)line->y1][(int)line->x1];
	zc.z1 = data->map[(int)line->y2][(int)line->x2];
	zc.color2 = data->color[(int)line->y2][(int)line->x2];
	zc.z *= data->zoom ;
	zc.z1 *= data->zoom;
	zoom_shift(data, line);
	three_dim(&line->x1, &line->y1, &zc.z, *data);
	three_dim(&line->x2, &line->y2, &zc.z1, *data);
	dda_h(&dda, line);
	i = 1;
	while (i <= dda.steps)
	{
		my_mlx_pixel_put(data, line->x1, line->y1, get_cr(zc.color1, zc.color2,
				(float)i / (float)dda.steps));
		line->x1 += dda.xinc;
		line->y1 += dda.yinc;
		i++;
	}
}

void	draw_stars(t_data *data)
{
	int	num_stars;
	int	i;
	int	x;
	int	y;

	i = 0;
	num_stars = 300;
	while (i < num_stars)
	{
		x = rand() % WIDTH;
		y = rand() % HEIGHT;
		my_mlx_pixel_put(data, x, y, 0xFFFFFF);
		i++;
	}
}

void	dda_draw(t_data *data)
{
	int		i;
	int		j;
	t_line	*line;

	line = malloc(sizeof(t_line));
	(!line) && (free_mem(data), exit(1), 0);
	j = 0;
	while (j < data->rows)
	{
		i = 0;
		while (i < data->columns)
		{
			(i < data->columns - 1)
				&& (line_x(line, i, j), dda_algo(line, data), 0);
			(j < data->rows - 1)
				&& (line_y(line, i, j), dda_algo(line, data), 0);
			i++;
		}
		j++;
	}
	draw_stars(data);
	free(line);
}
