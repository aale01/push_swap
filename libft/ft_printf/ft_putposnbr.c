/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putposnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:10:11 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:57:15 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive(unsigned long long n)
{
	char	c;

	if (n / 10 != 0)
		recursive(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putposnbr(unsigned long long n)
{
	recursive(n);
}
