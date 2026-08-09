/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:51:22 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:56:16 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_hexa_len(unsigned long nbr)
{
	int	i;

	if (!nbr)
		return (1);
	i = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

static int	format_hexa(unsigned long nbr, int width_fl, int prec_fl)
{
	int				bytes;
	unsigned int	len;

	bytes = 0;
	if (!nbr)
		len = 5;
	else
		len = ft_hexa_len(nbr);
	if (prec_fl > (int)len)
	{
		ft_putnchar('0', prec_fl - len);
		len = prec_fl;
	}
	else if (width_fl > 0 && width_fl > (int)len)
		bytes += ft_putnchar('0', width_fl - len);
	if (!nbr)
		write(1, "(nil)", 5);
	else
		ft_hexa(nbr, 'p');
	bytes += len;
	if (width_fl < 0 && - width_fl > (int)len)
		bytes += ft_putnchar(' ', - (width_fl + len));
	return (bytes);
}

static int	ft_putprefix(int *width_fl)
{
	write(1, "0x", 2);
	if (*width_fl > 0)
		*width_fl -= 2;
	else if (*width_fl < 0)
		*width_fl += 2;
	return (2);
}

int	ft_arg_ptr(const char *format, size_t size, unsigned long nbr)
{
	int				width;
	int				width_fl;
	int				precision_fl;
	int				bytes;

	bytes = 0;
	width = -1;
	width_fl = ft_search_width_format(format, size);
	if (width_fl == 0)
		width = ft_search_width(format, size);
	precision_fl = ft_search_precision_format(format, size);
	if (width_fl > 0 && precision_fl >= 0)
		width_fl = 0;
	if (nbr)
		width -= 2;
	if (width > 0)
	{
		width -= ft_max(2, ft_hexa_len(nbr), precision_fl);
		bytes += ft_putnchar(' ', width);
	}
	if (nbr)
		bytes += ft_putprefix(&width_fl);
	bytes += format_hexa(nbr, width_fl, precision_fl);
	return (bytes);
}
