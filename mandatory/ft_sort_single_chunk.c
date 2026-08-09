/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_single_chunk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 01:47:33 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/27 20:51:20 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_3(t_stack *stacks)
{
	t_list	*a;

	a = *stacks->a;
	if (*(int *)a->content > *(int *)a->next->content
		&& *(int *)a->content > *(int *)a->next->next->content)
		ra(stacks);
	else if (*(int *)a->content < *(int *)a->next->content
		&& *(int *)a->next->content > *(int *)a->next->next->content)
		rra(stacks);
	a = *stacks->a;
	if (*(int *)a->content > *(int *)a->next->content
		&& *(int *)a->content < *(int *)a->next->next->content)
		sa(stacks);
}

static void	push_min_to_b(t_stack *stacks, int pos)
{
	int		count_top;
	int		count_bot;
	t_list	*a;

	a = *stacks->a;
	count_top = 0;
	while (a && *(int *)a->content > stacks->arr[pos])
	{
		count_top++;
		a = a->next;
	}
	count_bot = ft_lstsize(*stacks->a) - count_top;
	if (count_top <= count_bot)
		while (count_top-- > 0)
			ra(stacks);
	else
		while (count_bot-- > 0)
			rra(stacks);
	pb(stacks);
}

void	ft_sort_single_chunk(t_stack *stacks)
{
	int		size;
	t_list	*a;

	a = *stacks->a;
	size = ft_lstsize(a);
	if (size == 2 && *(int *)a->content > *(int *)a->next->content)
		sa(stacks);
	else if (size == 3)
		ft_sort_3(stacks);
	else if (size == 4)
	{
		push_min_to_b(stacks, stacks->size - 4);
		ft_sort_3(stacks);
		pa(stacks);
	}
	else if (size == 5)
	{
		push_min_to_b(stacks, stacks->size - 5);
		push_min_to_b(stacks, stacks->size - 4);
		ft_sort_3(stacks);
		pa(stacks);
		pa(stacks);
	}
}
