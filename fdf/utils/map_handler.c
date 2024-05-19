/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:28:43 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/17 20:25:27 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_init(t_node *new_node, char *line, t_data *data, t_node **head)
{
	new_node->next = NULL;
	new_node->line = line;
	if (str_count(line, ' ') != 0)
		new_node->columns = str_count(line, ' ');
	else
	{
		free_list(*head);
		ft_error("Map Error");
		exit(1);
	}
	if (data->columns == 0)
		data->columns = new_node->columns;
	else if (data->columns != new_node->columns)
	{
		free_list(*head);
		ft_error("Map Error");
		exit(1);
	}
	data->rows++;
}

void	list_init(int fd, t_node **head, t_data *data)
{
	char	*line;
	t_node	*new_node;

	line = get_next_line(fd);
	(!line) && (free_list(*head)
		, free(data), ft_error("EMPTY MAP OR FILE ERROR"), exit(1), 0);
	new_node = malloc(sizeof(t_node));
	(!new_node) && (free_list(*head)
		, free(line), ft_error("ERROR"), exit(1), 0);
	*head = new_node;
	while (line != NULL)
	{
		ft_init(new_node, line, data, head);
		line = get_next_line(fd);
		if (line)
		{
			new_node->next = malloc(sizeof(t_node));
			(!new_node->next) && (free_list(*head)
				, free(line), ft_error("Memmory Error"), exit(1), 0);
			new_node = new_node->next;
		}
	}
	close(fd);
}

void	map_handler(char *file, t_node **head, t_data *data)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error("File Error");
		exit(1);
	}
	data->columns = 0;
	data->rows = 0;
	list_init(fd, head, data);
}
