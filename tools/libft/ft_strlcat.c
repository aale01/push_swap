/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:57:05 by abecucci          #+#    #+#             */
/*   Updated: 2024/12/27 15:07:56 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;
	unsigned int	j;

	j = ft_strlen(src);
	if (size == 0 && dest == NULL)
		return (j);
	l = ft_strlen(dest);
	if (size <= l)
		return (size + j);
	i = 0;
	if (size == 0 || l == size)
		return (l + j);
	while (i < size - l - 1 && src[i] != '\0')
	{
		dest[l + i] = src[i];
		i++;
	}
	if (l < size)
		dest[l + i] = '\0';
	return (l + j);
}
