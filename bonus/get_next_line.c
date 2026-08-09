/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:52:49 by alebe             #+#    #+#             */
/*   Updated: 2025/09/22 12:19:04 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE UINT_MAX
#endif

char	*read_line(int fd, char *line, char **stack)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = read(fd, line, (unsigned int)BUFFER_SIZE);
	while (bytes_read > 0)
	{
		line[bytes_read] = '\0';
		tmp = ft_strjoin((*stack), line);
		if (*stack)
			free(*stack);
		if (!tmp)
			return (NULL);
		*stack = tmp;
		if (ft_strchr((*stack), '\n'))
			break ;
		bytes_read = read(fd, line, (unsigned int)BUFFER_SIZE);
	}
	if (*stack && (bytes_read < 0 || (!bytes_read && !ft_strlen(*stack))))
	{
		free(*stack);
		*stack = NULL;
	}
	return (*stack);
}

char	*get_next_line(int fd)
{
	char				*line;
	char				*pos;
	char				*tmp;
	static char			*stack;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(((unsigned int)BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	stack = read_line(fd, line, &stack);
	free(line);
	if (!stack)
		return (NULL);
	tmp = stack;
	pos = ft_strchr(stack, '\n');
	if (!pos || pos == stack + ft_strlen(stack) - 1)
		pos = stack + ft_strlen(stack) - 1;
	line = ft_substr(stack, 0, pos - stack + 1);
	stack = ft_substr(pos + 1, 0, ft_strlen(pos + 1));
	free(tmp);
	return (line);
}
