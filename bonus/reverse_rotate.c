/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:14:02 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/22 15:12:47 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack *stacks)
{
	t_list	**a;
	t_list	*last;

	a = stacks->a;
	if (!(*a) || !((*a)->next))
		return ;
	last = ft_lstlast(*a);
	(last->prev)->next = NULL;
	ft_lstadd_front(a, last);
}

void	rrb(t_stack *stacks)
{
	t_list	**b;
	t_list	*last;

	b = stacks->b;
	if (!(*b) || !((*b)->next))
		return ;
	last = ft_lstlast(*b);
	(last->prev)->next = NULL;
	ft_lstadd_front(b, last);
}

void	rrr(t_stack *stacks)
{
	rra(stacks);
	rrb(stacks);
}
