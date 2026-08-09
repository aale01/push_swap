/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:12:36 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:56:29 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_numlen(unsigned int nbr)
{
	int	count;

	if (!nbr)
		return (1);
	count = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static int	format_nbr(unsigned int nbr, int width_fl, int prec_fl)
{
	int				bytes;
	unsigned int	num_len;

	bytes = 0;
	num_len = ft_numlen(nbr);
	if (prec_fl > (int)num_len)
	{
		ft_putnchar('0', prec_fl - num_len);
		num_len = prec_fl;
	}
	else if (width_fl > 0 && width_fl > (int)num_len)
		bytes += ft_putnchar('0', width_fl - num_len);
	ft_putposnbr(nbr);
	bytes += num_len;
	if (width_fl < 0 && - width_fl > (int)num_len)
		bytes += ft_putnchar(' ', - (width_fl + num_len));
	return (bytes);
}

int	ft_arg_uint(const char *format, size_t size, unsigned int nbr)
{
	int	width;
	int	width_fl;
	int	prec_fl;
	int	bytes;

	bytes = 0;
	width = -1;
	width_fl = ft_search_width_format(format, size);
	if (width_fl == 0)
		width = ft_search_width(format, size);
	prec_fl = ft_search_precision_format(format, size);
	if (width_fl > 0 && prec_fl >= 0)
		width_fl = 0;
	if (width > 0)
		bytes += ft_putnchar(' ', width - ft_max(2, ft_numlen(nbr), prec_fl));
	bytes += format_nbr(nbr, width_fl, prec_fl);
	return (bytes);
}
