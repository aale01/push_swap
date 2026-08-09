/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:33:42 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:56:39 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(const int n, ...)
{
	int		nbr;
	int		max;
	int		count;
	va_list	args;

	va_start(args, n);
	max = va_arg(args, int);
	count = n;
	while (--count > 0)
	{
		nbr = va_arg(args, int);
		if (nbr > max)
			max = nbr;
	}
	va_end(args);
	return (max);
}
