/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:22:12 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/10 04:52:43 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_top(t_list *lst, int pivot)
{
	int	count;

	count = 0;
	while (lst && *(int *)lst->content != pivot)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

static int	ft_count_bot(t_list *lst, int pivot)
{
	int	count;

	count = 0;
	while (lst && *(int *)lst->content != pivot)
	{
		count++;
		lst = lst->prev;
	}
	return (count);
}

static int	ft_place_below_a(t_stack *stacks)
{
	int	num;
	int	max;

	num = *(int *)(*stacks->b)->content;
	if (*stacks->a)
		max = *(int *)ft_lstlast(*stacks->a)->content;
	if (!(*stacks->a)
		|| num > max
		|| max == stacks->arr[stacks->size - 1])
	{
		pa(stacks);
		ra(stacks);
		return (1);
	}
	return (0);
}

static void	ft_sort(t_stack *stacks, int n)
{
	if (ft_count_top(*stacks->b, n) <= ft_count_bot(ft_lstlast(*stacks->b), n))
	{
		while (*(int *)(*stacks->b)->content != n)
			if (!ft_place_below_a(stacks))
				rb(stacks);
	}
	else
	{
		while (*(int *)ft_lstlast(*stacks->b)->content != n)
		{
			rrb(stacks);
			ft_place_below_a(stacks);
		}
		rrb(stacks);
	}
	pa(stacks);
}

void	ft_sort_chunk(t_stack *stacks)
{
	int			i;
	int			max;
	static int	chunk = -1;
	static int	index = -1;

	if (chunk == -1 && index == -1)
	{
		chunk = stacks->num_chunk;
		index = stacks->size - ft_lstsize(*stacks->a) - 1;
	}
	chunk--;
	i = 0;
	while (i < stacks->chunk_size[chunk])
	{
		max = stacks->arr[index--];
		if (*stacks->a && *(int *)ft_lstlast(*stacks->a)->content == max)
			rra(stacks);
		else
			ft_sort(stacks, max);
		i++;
	}
}
