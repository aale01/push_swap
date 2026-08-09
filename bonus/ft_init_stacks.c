/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:53:37 by abecucci          #+#    #+#             */
/*   Updated: 2025/10/11 23:13:58 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_check_int(char *num)
{
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

static int	ft_check_dup(t_list *head, int num)
{
	while (head)
	{
		if (num == *(int *)head->content)
			return (0);
		head = head->next;
	}
	return (1);
}

static int	*ft_set_num(t_list *a, char *str)
{
	int	*num;
	int	sign;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	if (!*str || !ft_check_int(str))
		return (NULL);
	if (ft_strlen(str) > 10 || (ft_strlen(str) == 10
			&& ((sign == -1 && ft_strncmp(str, "2147483648", 10) > 0)
				|| (sign == 1 && ft_strncmp(str, "2147483647", 10) > 0))))
		return (NULL);
	num = (int *)malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = sign * ft_atoi(str);
	if (!ft_check_dup(a, *num))
	{
		free(num);
		return (NULL);
	}
	return (num);
}

static int	ft_set_stacks(t_stack *stacks)
{
	stacks->a = (t_list **)malloc(sizeof(t_list *));
	stacks->b = (t_list **)malloc(sizeof(t_list *));
	stacks->cmds = (t_list **)malloc(sizeof(t_list *));
	if (!stacks->a || !stacks->b || !stacks->cmds)
		return (0);
	*(stacks->a) = NULL;
	*(stacks->b) = NULL;
	*(stacks->cmds) = NULL;
	return (1);
}

int	ft_init_stacks(t_stack *stacks, int size, char *argv[])
{
	int		i;
	int		*num;
	t_list	*node;

	if (!ft_set_stacks(stacks))
		return (0);
	i = 0;
	while (i++ < size)
	{
		num = ft_set_num(*stacks->a, argv[i]);
		if (!num)
			return (0);
		node = ft_lstnew(num);
		if (!node)
		{
			free(num);
			return (0);
		}
		ft_lstadd_back(stacks->a, node);
	}
	return (1);
}
