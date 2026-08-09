/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:11:34 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:56:50 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		bytes;
	va_list	args;

	va_start(args, format);
	bytes = 0;
	while (*format)
	{
		while (*format != '%')
		{
			write(1, format, 1);
			bytes++;
			format++;
			if (!*format)
				break ;
		}
		if (!*format)
			break ;
		format++;
		bytes += ft_arg_print(&format, args);
	}
	va_end(args);
	return (bytes);
}
