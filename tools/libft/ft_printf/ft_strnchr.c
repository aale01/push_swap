/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:33:46 by abecucci          #+#    #+#             */
/*   Updated: 2025/04/03 19:57:37 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnchr(const char *s, size_t size, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && i < size)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(&(s[i])));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(&(s[i])));
	else
		return (NULL);
}
