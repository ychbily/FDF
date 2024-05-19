/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:32:20 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/10 20:31:17 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_mem(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->rows)
	{
		free(data->map[j]);
		free(data->color[j]);
		j++;
	}
	free(data->map);
	free(data->color);
}
