/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:18 by abecucci          #+#    #+#             */
/*   Updated: 2025/10/11 23:10:31 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_fix_sum_tot(t_stack *stacks, int sum_sizes, int *pairs)
{
	int	i;
	int	diff;

	diff = stacks->size - sum_sizes;
	i = 0;
	while (i < stacks->num_chunk && diff > 0)
	{
		if (pairs[i] % 2)
		{
			pairs[i]++;
			diff--;
		}
		i++;
	}
}

static void	ft_set_4_6_chunks_size(t_stack *stacks)
{
	int	i;
	int	sum;
	int	parts;
	int	pairs[3];

	parts = 3 * stacks->num_chunk / 2;
	pairs[0] = stacks->num_chunk * stacks->size / parts;
	pairs[1] = 2 * stacks->size / parts;
	if (stacks->num_chunk == 6)
		pairs[2] = stacks->size / parts;
	i = -1;
	sum = 0;
	while (++i < stacks->num_chunk / 2)
		sum += pairs[i];
	if (sum < stacks->size - 1)
		ft_fix_sum_tot(stacks, sum, pairs);
	i = 0;
	while (i < stacks->num_chunk / 2)
	{
		stacks->chunk_size[2 * i] = pairs[i] / 2;
		stacks->chunk_size[2 * i + 1] = stacks->chunk_size[2 * i];
		i++;
	}
}

static void	ft_set_10_and_big_chunks_size(t_stack *stacks)
{
	int	i;
	int	sum;
	int	parts;
	int	pairs[7];

	i = 0;
	sum = 0;
	if (stacks->num_chunk == 10)
		parts = 15;
	else
		parts = 28;
	while (i < stacks->num_chunk / 2)
	{
		pairs[i] = (stacks->num_chunk / 2 - i) * stacks->size / parts;
		sum += pairs[i];
		i++;
	}
	if (sum < stacks->size - 1)
		ft_fix_sum_tot(stacks, sum, pairs);
	i = 0;
	while (i < stacks->num_chunk / 2)
	{
		stacks->chunk_size[2 * i] = pairs[i] / 2;
		stacks->chunk_size[2 * i + 1] = stacks->chunk_size[2 * i];
		i++;
	}
}

static void	ft_set_chunks_size(t_stack *stacks)
{
	stacks->chunk_size = (int *)malloc(stacks->num_chunk * sizeof(int));
	if (!stacks->chunk_size)
		ft_error(stacks);
	if (stacks->num_chunk == 1)
		stacks->chunk_size[0] = stacks->size;
	else if (stacks->num_chunk == 2)
	{
		stacks->chunk_size[0] = stacks->size / 2;
		stacks->chunk_size[1] = stacks->size - stacks->chunk_size[0];
	}
	else if (stacks->num_chunk == 4 || stacks->num_chunk == 6)
	{
		ft_set_4_6_chunks_size(stacks);
	}
	else if (stacks->num_chunk == 10 || stacks->num_chunk == 14)
		ft_set_10_and_big_chunks_size(stacks);
}

void	ft_init_chunks(t_stack *stacks)
{
	int			i;
	const int	values[5] = {1, 2, 4, 6, 10};
	const int	thresholds[5] = {10, 20, 60, 100, 500};

	i = 0;
	while (i < 5)
	{
		if (stacks->size <= thresholds[i])
		{
			stacks->num_chunk = values[i];
			break ;
		}
		i++;
	}
	if (i == 5)
		stacks->num_chunk = 14;
	ft_set_chunks_size(stacks);
}
