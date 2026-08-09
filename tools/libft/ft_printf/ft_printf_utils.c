/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:51:15 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 19:56:58 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

static size_t	ft_strseplen(const char *str, const char *set)
{
	size_t	i;

	i = 0;
	while (!ft_strchr(set, str[i]))
		i++;
	return (i + 1);
}

static int	arg_option_print(const char *format, size_t size, va_list args)
{
	unsigned long	nbr;

	if (format[size - 1] == 'c')
		return (ft_arg_char(format, size, (va_arg(args, int))));
	else if (format[size - 1] == 's')
		return (ft_arg_str(format, size, va_arg(args, char *)));
	else if (format[size - 1] == 'p')
	{
		nbr = (unsigned long)va_arg(args, void *);
		return (ft_arg_ptr(format, size, nbr));
	}
	else if (format[size - 1] == 'd' || format[size - 1] == 'i')
		return (ft_arg_int(format, size, va_arg(args, int)));
	else if (format[size - 1] == 'u')
		return (ft_arg_uint(format, size, va_arg(args, unsigned int)));
	else if (format[size - 1] == 'x' || format[size - 1] == 'X')
		return (ft_arg_hexa(format, size, va_arg(args, unsigned int)));
	else if (format[size - 1] == '%')
		return (ft_arg_str(format, size, "%"));
	return (0);
}

int	ft_arg_print(const char **format, va_list args)
{
	int		bytes;
	size_t	size;

	size = ft_strseplen(*format, "cspdiuxX%");
	bytes = arg_option_print(*format, size, args);
	*format += size;
	return (bytes);
}
