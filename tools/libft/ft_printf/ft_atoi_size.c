/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:23:55 by abecucci          #+#    #+#             */
/*   Updated: 2025/04/03 19:56:34 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi_size(const char *str, size_t size)
{
	int		result;
	int		sign;
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]) && i < size)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
