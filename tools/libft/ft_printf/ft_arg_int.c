/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:12:36 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:56:09 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_numlen(int nbr)
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

static int	ft_sign(int nbr, int sign_fl)
{
	int	bytes;

	bytes = 0;
	if (nbr >= 0 && sign_fl != 0)
	{
		if (sign_fl == -1)
			write(1, " ", 1);
		else if (sign_fl == 1)
			write(1, "+", 1);
		bytes++;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		bytes++;
	}
	return (bytes);
}

static int	format_nbr(int nbr, int width_fl, int sign_fl, int prec_fl)
{
	int				bytes;
	unsigned int	num_len;

	bytes = 0;
	if ((nbr >= 0 && sign_fl) || nbr < 0)
	{
		if (width_fl > 0)
			width_fl--;
		else if (width_fl < 0)
			width_fl++;
	}
	bytes += ft_sign(nbr, sign_fl);
	num_len = ft_numlen(nbr);
	if (prec_fl > (int)num_len)
	{
		ft_putnchar('0', prec_fl - num_len);
		num_len = prec_fl;
	}
	else if (width_fl > 0 && width_fl > (int)num_len)
		bytes += ft_putnchar('0', width_fl - num_len);
	ft_putposnbr(ft_abs(nbr));
	bytes += num_len;
	if (width_fl < 0 && - width_fl > (int)num_len)
		bytes += ft_putnchar(' ', - (width_fl + num_len));
	return (bytes);
}

static int	ft_search_sign_format(const char *format, size_t size, int nbr)
{
	int	sign_flag;

	sign_flag = 0;
	if (ft_strnchr(format, size, ' '))
		sign_flag = -1;
	else if (ft_strnchr(format, size, '+'))
		sign_flag = 1;
	else if (nbr < 0)
		sign_flag = 1;
	return (sign_flag);
}

int	ft_arg_int(const char *format, size_t size, int nbr)
{
	int	width;
	int	width_fl;
	int	sign_fl;
	int	precision_fl;
	int	bytes;

	bytes = 0;
	width = -1;
	width_fl = ft_search_width_format(format, size);
	if (width_fl == 0)
		width = ft_search_width(format, size);
	sign_fl = ft_search_sign_format(format, size, nbr);
	precision_fl = ft_search_precision_format(format, size);
	if (width_fl > 0 && precision_fl >= 0)
		width_fl = 0;
	if (sign_fl)
		width--;
	if (width > 0)
	{
		width -= ft_max(2, ft_numlen(nbr), precision_fl);
		bytes += ft_putnchar(' ', width);
	}
	bytes += format_nbr(nbr, width_fl, sign_fl, precision_fl);
	return (bytes);
}
