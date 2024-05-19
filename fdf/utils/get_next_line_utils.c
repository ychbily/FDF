/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 03:40:49 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/17 20:28:01 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_len(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*f_dup(char *str, int len)
{
	char	*ptr;
	int		i;

	if (!str || !len)
		return (NULL);
	i = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (free(ptr), NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
	free(ptr);
}

char	*ft_append(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_len(s2);
	if (!s1)
		return (f_dup(s2, len));
	len = len + ft_len(s1);
	str = malloc(len + 1);
	if (!str)
		return (free(s1), NULL);
	len = 0;
	while (s1[i])
		str[len++] = s1[i++];
	i = 0;
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	free(s1);
	return (str);
}

int	new_ln(char *buf)
{
	int	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_line(char **buf)
{
	int		i;
	char	*line;
	char	*str;

	if (!*buf)
		return (NULL);
	str = *buf;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = f_dup(str, i);
	if (!line)
		return (free(*buf),*buf = NULL, NULL);
	*buf = f_dup(str + i, ft_len(str + i));
	if (str)
		free(str);
	str = NULL;
	return (line);
}
