/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:43:10 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/25 12:04:14 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_find_and_execute_cmd(t_stack *stacks, void *cmd)
{
	if (!ft_memcmp(cmd, "sa\n", 4))
		sa(stacks);
	else if (!ft_memcmp(cmd, "sb\n", 4))
		sb(stacks);
	else if (!ft_memcmp(cmd, "ss\n", 4))
		ss(stacks);
	else if (!ft_memcmp(cmd, "pa\n", 4))
		pa(stacks);
	else if (!ft_memcmp(cmd, "pb\n", 4))
		pb(stacks);
	else if (!ft_memcmp(cmd, "ra\n", 4))
		ra(stacks);
	else if (!ft_memcmp(cmd, "rb\n", 4))
		rb(stacks);
	else if (!ft_memcmp(cmd, "rr\n", 4))
		rr(stacks);
	else if (!ft_memcmp(cmd, "rra\n", 5))
		rra(stacks);
	else if (!ft_memcmp(cmd, "rrb\n", 5))
		rrb(stacks);
	else if (!ft_memcmp(cmd, "rrr\n", 5))
		rrr(stacks);
	else
		return (0);
	return (1);
}

int	ft_execute_cmds(t_stack *stacks)
{
	t_list	*cmd;

	cmd = *stacks->cmds;
	while (cmd)
	{
		if (!ft_find_and_execute_cmd(stacks, cmd->content))
			return (0);
		cmd = cmd->next;
	}
	return (1);
}
