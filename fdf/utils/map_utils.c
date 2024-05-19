/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:40:01 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/17 20:39:17 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	str_count(char const *s, char c)
{
	int	count;
	int	str;

	count = 0;
	str = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			str = 0;
		else if (str == 0 && *s != '\n')
		{
			str = 1;
			count++;
		}
		s++;
	}
	return (count);
}

void	filling(char **tmp, int *color, int j)
{
	if (tmp[1] != NULL)
		color[j] = ft_atoi_base(tmp[1], 16);
	else if (ft_atoi(tmp[0]) != 0 && !tmp[1])
		color[j] = 0x8A2BE2;
	else if (ft_atoi(tmp[0]) == 0 && !tmp[1])
		color[j] = 0xFFFFFF;
	else
		color[j] = 0xFFFF00;
	return ;
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	fill_map(int *map, int *color, char *line, int columns)
{
	char	**mp;
	int		j;
	char	**tmp;

	mp = ft_split(line, ' ');
	(!mp) && (ft_error("Memmory Error"), exit(1), 0);
	j = 0;
	while (mp[j] != NULL && j < columns)
	{
		tmp = ft_split(mp[j], ',');
		(!tmp) && (ft_error("Memmory Error"), exit(1), 0);
		(ft_atoi(tmp[0]) >= 300)
			&& (ft_error("Z is too high \nTRY ANOTHER MAP")
			, free(tmp[0]), free(tmp[1]), free(tmp), free(mp), exit(1), 0);
		filling(tmp, color, j);
		if (j < columns)
			map[j] = ft_atoi(tmp[0]);
		free(tmp[0]);
		if (tmp[1])
			free(tmp[1]);
		free(tmp);
		j++;
	}
	free_str(mp);
}

void	allocate_map(t_data *data)
{
	int	i;

	data->map = malloc(sizeof(int *) * (data->rows + 1));
	(!data->map) && (ft_error("Memmory Error"), exit(1), 0);
	data->color = malloc(sizeof(int *) * (data->rows + 1));
	(!data->color)
		&& (ft_error("Memmory Error"), free(data->map), exit(1), 0);
	i = 0;
	while (i < data->rows)
	{
		data->map[i] = malloc(sizeof(int) * (data->columns + 1));
		data->color[i] = malloc(sizeof(int) * (data->columns + 1));
		(!data->map[i] || !data->color[i])
			&& (ft_error("Memmory Error"), exit(1), 0);
		i++;
	}
}
