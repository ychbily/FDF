/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:26:37 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/10 17:37:58 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom_shift(t_data *data, t_line *line)
{
	line->x1 *= data->zoom;
	line->x2 *= data->zoom;
	line->y1 *= data->zoom;
	line->y2 *= data->zoom;
	line->x1 += data->shift_x;
	line->y1 += data->shift_y;
	line->x2 += data->shift_x;
	line->y2 += data->shift_y;
}
