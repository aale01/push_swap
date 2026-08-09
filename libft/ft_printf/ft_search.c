/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:15:45 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:57:29 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_precision_format(const char *format, size_t size)
{
	size_t	start;
	int		precision_flag;

	if (!ft_strnchr(format, size, '.'))
		return (-1);
	start = 0;
	while (format[start] != '.' && start < size)
		start++;
	precision_flag = ft_atoi_size(format + start + 1, size - start);
	if (precision_flag == 0 && format[size - 1] != 's')
		precision_flag = 1;
	return (precision_flag);
}

int	ft_search_width(const char *format, size_t size)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (ft_strnchr("-0+ #", 6, format[start]))
		start++;
	end = 0;
	while (format[end] != '.' && end < size)
		end++;
	return (ft_atoi_size(format + start, end - start));
}

int	ft_search_width_format(const char *format, size_t size)
{
	int	i;
	int	width_flag;
	int	width;

	i = 0;
	while (ft_strnchr("-0.+ #", 6, format[i]))
		i++;
	width_flag = 0;
	if (ft_strnchr(format, i, '-'))
		width_flag = -1;
	else if (ft_strnchr(format, i, '0'))
		width_flag = 1;
	width = ft_search_width(format, size);
	width_flag *= width;
	return (width_flag);
}
