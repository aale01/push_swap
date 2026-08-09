/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:02:05 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/06 20:50:27 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
			swap(&arr[i], &arr[min_idx]);
		i++;
	}
}

void	ft_set_arr(t_stack *stacks)
{
	int		i;
	t_list	*a;

	i = 0;
	a = *stacks->a;
	while (i < stacks->size)
	{
		stacks->arr[i] = *(int *)a->content;
		a = a->next;
		i++;
	}
	ft_bubble_sort(stacks->arr, stacks->size);
}
