/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:09:36 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:55:54 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_char(char c, int width, int width_fl, int prec_fl)
{
	int				bytes;
	unsigned int	len;

	bytes = 0;
	len = 1;
	if (prec_fl >= 0 && prec_fl < 1)
		len = prec_fl;
	if (width > 0)
		bytes += ft_putnchar(' ', width - len);
	else if (width_fl > 0 && width_fl > 1)
		bytes += ft_putnchar('0', width_fl - len);
	if (len)
		write(1, &c, 1);
	bytes += len;
	if (width_fl < 0 && - width_fl > 1)
		bytes += ft_putnchar(' ', - (width_fl + 1));
	return (bytes);
}

int	ft_arg_char(const char *format, size_t size, char c)
{
	int		width;
	int		width_fl;
	int		precision_fl;
	int		bytes;
	char	a;

	a = c;
	bytes = 0;
	width = -1;
	width_fl = ft_search_width_format(format, size);
	if (width_fl == 0)
		width = ft_search_width(format, size);
	precision_fl = ft_search_precision_format(format, size);
	if (width_fl > 0 && precision_fl >= 0)
		width_fl = 0;
	bytes += ft_format_char(a, width, width_fl, precision_fl);
	return (bytes);
}
