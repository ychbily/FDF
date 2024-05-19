/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:51:00 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/11 19:25:40 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

void	shift_str(char **str, int *sign)
{
	while (**str == ' ' || **str == '\t' || **str == '\n'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

void	str_search(char **str, char **str1)
{
	*str = ft_strchr(*str1, 'x');
	if (!*str)
		*str = ft_strchr(*str1, 'x');
	if (!*str)
		*str = *str1;
}

int	ft_atoi_base(char *str1, int base)
{
	int		result;
	int		sign;
	int		digit;
	char	*str;

	result = 0;
	sign = 1;
	str_search(&str, &str1);
	str++;
	shift_str(&str, &sign);
	while (*str)
	{
		digit = char_to_digit(*str);
		if (digit >= 0 && digit < base)
		{
			result = result * base + digit;
			str++;
		}
		else
			break ;
	}
	return (result * sign);
}
