/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:46:50 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/02 16:03:10 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0' )
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
