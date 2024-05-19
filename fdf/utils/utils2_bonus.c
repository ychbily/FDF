/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:14:37 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/15 00:23:36 by ychbily          ###   ########.fr       */
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
	exit(1);
}
