/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:26:55 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/27 22:29:02 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
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

int	ft_read_cmds(t_stack *stacks)
{
	char	*cmd;
	t_list	*node;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		node = ft_lstnew(cmd);
		if (node)
			ft_lstadd_back(stacks->cmds, ft_lstnew(cmd));
		else
		{
			free(cmd);
			return (0);
		}
		cmd = get_next_line(STDIN_FILENO);
	}
	return (1);
}
