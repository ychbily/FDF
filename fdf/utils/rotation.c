/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 02:47:24 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/10 17:37:49 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rot_x(float *y, float *z, double angle)
{
	int	y0;

	y0 = *y;
	*y = y0 * cos(angle) + *z * sin(angle);
	*z = -y0 * sin(angle) + *z * cos(angle);
}

void	rot_y(float *x, float *z, double angle)
{
	int	x0;

	x0 = *x;
	*x = x0 * cos(angle) + *z * sin(angle);
	*z = -x0 * sin(angle) + *z * cos(angle);
}

void	rot_z(float *x, float *y, double angle)
{
	int		x0;
	int		y0;

	x0 = *x;
	y0 = *y;
	*x = x0 * cos(angle) + y0 * sin(angle);
	*y = -x0 * sin(angle) + y0 * cos(angle);
}

void	three_dim(float *x, float *y, float *z, t_data v)
{
	rot_x(y, z, v.x_teta);
	rot_y(x, z, v.y_teta);
	rot_z(x, y, v.z_teta);
}

float	v_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}
