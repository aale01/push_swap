/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:59:22 by abecucci          #+#    #+#             */
/*   Updated: 2025/04/03 19:56:23 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_format_str(const char *str, int width, int width_fl, int prec_fl)
{
	int				bytes;
	unsigned int	len;

	bytes = 0;
	len = ft_strlen(str);
	if (prec_fl >= 0 && prec_fl < (int)len)
		len = prec_fl;
	if (width > 0)
		bytes += ft_putnchar(' ', width - len);
	else if (width_fl > 0 && width_fl > (int)len)
		bytes += ft_putnchar('0', width_fl - len);
	write(1, str, len);
	bytes += len;
	if (width_fl < 0 && - width_fl > (int)len)
		bytes += ft_putnchar(' ', - (width_fl + len));
	return (bytes);
}

int	ft_arg_str(const char *format, size_t size, const char *str)
{
	int	width;
	int	width_fl;
	int	precision_fl;
	int	bytes;

	bytes = 0;
	width = -1;
	if (!str)
		return (write(1, "(null)", 6));
	width_fl = ft_search_width_format(format, size);
	if (width_fl == 0)
		width = ft_search_width(format, size);
	precision_fl = ft_search_precision_format(format, size);
	if (width_fl > 0 && precision_fl >= 0)
		width_fl = 0;
	bytes += ft_format_str(str, width, width_fl, precision_fl);
	return (bytes);
}
