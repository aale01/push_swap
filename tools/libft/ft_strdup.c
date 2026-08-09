/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:06:51 by abecucci          #+#    #+#             */
/*   Updated: 2024/12/16 16:01:52 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*p;

	size = ft_strlen(src);
	p = (char *)malloc((size + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
