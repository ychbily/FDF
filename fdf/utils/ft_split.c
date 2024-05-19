/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:32:39 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/17 20:37:06 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

int	counter_str(char const *s, char c)
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
		else if (str == 0)
		{
			str = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**rtrn(char **ptr, int j)
{
	while (j > 0)
	{
		j--;
		free(ptr[j]);
	}
	free(ptr);
	return (NULL);
}

char	**sp(char const *s, char c, int counted, char **ptr)
{
	int	j;
	int	i;

	j = 0;
	while (j < counted)
	{
		i = 0;
		while (s[i] == c && s[i] != 0)
			s++;
		while (s[i] != c && s[i] != 0)
			i++;
		ptr[j] = ft_calloc(i + 1, 1);
		if (ptr[j] == NULL )
			return (rtrn(ptr, j));
		ft_strlcpy(ptr[j], s, i + 1);
		s += i;
		j++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		counted;

	counted = counter_str(s, c);
	if (!s)
		return (NULL);
	ptr = ft_calloc(counted + 1, sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	return (sp(s, c, counted, ptr));
}
