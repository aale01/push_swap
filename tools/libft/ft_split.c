/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:11:40 by abecucci          #+#    #+#             */
/*   Updated: 2024/12/24 17:56:30 by alebe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != sep)
			i++;
	}
	return (count);
}

static int	ft_strlen_split(const char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != sep)
		i++;
	return (i);
}

static void	set_text(const char *str, char sep, char **text, int wordnum)
{
	int	i;
	int	pos;
	int	wordlen;

	i = 0;
	pos = -1;
	while (++pos < wordnum)
	{
		while (str[i] == sep && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			break ;
		wordlen = ft_strlen_split(&str[i], sep);
		text[pos] = (char *)malloc((wordlen + 1) * sizeof(char));
		if (!text[pos])
		{
			while (--pos >= 0)
				free(text[pos]);
			free(text);
		}
		ft_strlcpy(text[pos], &str[i], wordlen + 1);
		i += wordlen;
	}
}

char	**ft_split(const char *str, char sep)
{
	int		wordnum;
	char	**text;

	if (!str)
		return (NULL);
	wordnum = count_words(str, sep);
	text = (char **)malloc((wordnum + 1) * sizeof(char *));
	if (!text)
		return (NULL);
	set_text(str, sep, text, wordnum);
	text[wordnum] = NULL;
	return (text);
}
