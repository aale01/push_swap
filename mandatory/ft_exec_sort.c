/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 23:42:46 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/10 04:52:43 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_divide_chunk(t_stack *stacks)
{
	int			i;
	int			pivot1;
	int			pivot2;
	static int	chunk = 0;
	static int	index = -1;

	i = index;
	index += stacks->chunk_size[chunk++];
	pivot1 = stacks->arr[index];
	index += stacks->chunk_size[chunk++];
	pivot2 = stacks->arr[index];
	while (i < index)
	{
		if (*(int *)(*stacks->a)->content <= pivot2)
		{
			pb(stacks);
			if (*(int *)(*stacks->b)->content <= pivot1)
				rb(stacks);
			i++;
		}
		else
			ra(stacks);
	}
}

void	ft_divide_et_impera(t_stack *stacks)
{
	int	i;

	if (stacks->size == 1)
		return ;
	i = 0;
	if (stacks->num_chunk > 1)
	{
		while (i < stacks->num_chunk)
		{
			ft_divide_chunk(stacks);
			i += 2;
		}
	}
	ft_impera(stacks);
}
