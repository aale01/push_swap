/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:26:54 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:57:05 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned long nbr, char *base, int base_num)
{
	char	c;

	if (nbr / base_num != 0)
		ft_putnbr_base(nbr / base_num, base, base_num);
	c = base[nbr % base_num];
	write(1, &c, 1);
}

void	ft_hexa(unsigned long nbr, char c)
{
	if (c == 'x' || c == 'p')
		ft_putnbr_base(nbr, "0123456789abcdef", 16);
	else if (c == 'X')
		ft_putnbr_base(nbr, "0123456789ABCDEF", 16);
}
