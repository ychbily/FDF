/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 02:48:52 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/17 20:24:20 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buf), buf = NULL, NULL);
	line = malloc((size_t)BUFFER_SIZE + 1);
	if (!line)
		return (free(buf), free(line), buf = NULL, NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, line, BUFFER_SIZE);
		if (readed == -1)
			return (NULL);
		line[readed] = '\0';
		buf = ft_append(buf, line);
		if (new_ln(buf))
			break ;
	}
	if (line)
		free(line);
	line = NULL;
	return (ft_line(&buf));
}
