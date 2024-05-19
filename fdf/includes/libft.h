/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:14:41 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/11 19:33:06 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t n);
char	**ft_split(char const *s, char c);
int		ft_atoi_base(char *str1, int base);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
int		str_count(char const *s, char c);

#endif
