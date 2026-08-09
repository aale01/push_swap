/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:02:29 by alebe             #+#    #+#             */
/*   Updated: 2024/12/24 17:51:32 by alebe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_del_char(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!set)
		return (0);
	while (ft_strchr(set, s1[i]) && s1[i])
	{
		count++;
		i++;
	}
	if (!s1[i])
		return (count);
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i--]))
		count++;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		trimmed_len;
	char	*trimmed_str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	trimmed_len = ft_strlen(s1) - count_del_char(s1, set);
	trimmed_str = (char *)malloc((trimmed_len + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	while (i < trimmed_len)
	{
		trimmed_str[i] = *s1;
		i++;
		s1++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
