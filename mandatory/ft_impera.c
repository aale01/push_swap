/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_impera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:08:34 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/10 04:35:01 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_cycle(t_stack *stacks, int count, void (*cmd)(t_stack *))
{
	int	i;

	i = 0;
	while (i < count)
	{
		cmd(stacks);
		i++;
	}
}

static int	ft_count_top(t_list *lst, int pivot)
{
	int	count;

	count = 0;
	while (lst && *(int *)lst->content > pivot)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

static void	ft_sort_last(t_stack *stacks, int pivot)
{
	int	dist_top;
	int	dist_bot;

	dist_top = ft_count_top(*stacks->a, pivot);
	dist_bot = ft_lstsize(*stacks->a) - dist_top;
	if (dist_top <= dist_bot)
		ft_cycle(stacks, dist_top, ra);
	else
		ft_cycle(stacks, dist_bot, rra);
	pb(stacks);
}

void	ft_impera(t_stack *stacks)
{
	int	i;
	int	min;
	int	rest_size;

	rest_size = ft_lstsize(*stacks->a);
	if (rest_size <= 5)
		ft_sort_single_chunk(stacks);
	else
	{
		i = 0;
		while (i < rest_size)
		{
			min = stacks->arr[stacks->size - rest_size + i];
			ft_sort_last(stacks, min);
			i++;
		}
		while (i-- > 0)
			pa(stacks);
	}
	i = 0;
	if (stacks->num_chunk > 1)
		while (i++ < stacks->num_chunk)
			ft_sort_chunk(stacks);
}
