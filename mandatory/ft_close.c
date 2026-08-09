/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 23:23:58 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/10 04:35:02 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_close(t_stack *stacks)
{
	ft_lstclear(stacks->a, free);
	free(stacks->a);
	ft_lstclear(stacks->b, free);
	free(stacks->b);
	ft_lstclear(stacks->cmds, free);
	free(stacks->cmds);
	if (stacks->arr)
		free(stacks->arr);
	if (stacks->chunk_size)
		free(stacks->chunk_size);
}

void	ft_error(t_stack *stacks)
{
	ft_close(stacks);
	write(2, "Error\n", 6);
	exit(0);
}
