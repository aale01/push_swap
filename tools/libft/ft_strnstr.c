/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:34:18 by abecucci          #+#    #+#             */
/*   Updated: 2024/12/27 15:34:24 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	to_find_len;

	if (to_find[0] == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	to_find_len = ft_strlen(to_find);
	i = 0;
	while (str[i] != '\0' && i <= len - to_find_len)
	{
		if (!ft_strncmp(&(str[i]), to_find, to_find_len))
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
