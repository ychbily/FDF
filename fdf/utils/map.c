/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:13:12 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/15 01:41:30 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_list(t_node *head)
{
	t_node	*tmp;

	tmp = NULL;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->line);
		free(tmp);
	}
}

void	map(t_data *data, char *file)
{
	int		i;
	t_node	*head;
	t_node	*tmp;

	tmp = NULL;
	head = NULL;
	map_handler(file, &head, data);
	allocate_map(data);
	i = 0;
	tmp = head;
	while (tmp != NULL)
	{
		fill_map(data->map[i], data->color[i], tmp->line, data->columns);
		i++;
		tmp = tmp->next;
	}
	i = 0;
	free_list(head);
}
