/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 01:31:36 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/10 20:09:07 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

unsigned int	get_cr(unsigned int color1, unsigned int color2, float t)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (((color1 >> 16) & 0xFF) * (1 - t) + ((color2 >> 16) & 0xFF) * t);
	g = (((color1 >> 8) & 0xFF) * (1 - t) + ((color2 >> 8) & 0xFF) * t);
	b = (((color1) & 0xFF) * (1 - t) + ((color2) & 0xFF) * t);
	return ((r << 16 | g << 8 | b) & 0xFFFFFF);
}

void	parralel_init(t_data *data)
{
	data->x_teta = 0;
	data->y_teta = 0;
	data->z_teta = 0;
}

void	line_x(t_line *line, int i, int j)
{
	line->x1 = i;
	line->x2 = i + 1;
	line->y1 = j;
	line->y2 = j;
}

void	line_y(t_line *line, int i, int j)
{
	line->x1 = i;
	line->x2 = i;
	line->y1 = j;
	line->y2 = j + 1;
}

int	min_v(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
