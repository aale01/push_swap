/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:02:33 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/22 15:12:47 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack *stacks)
{
	t_list	**a;
	t_list	*head;

	a = stacks->a;
	if (!(*a) || !((*a)->next))
		return ;
	head = *a;
	*a = head->next;
	(*a)->prev = NULL;
	ft_lstadd_back(a, head);
	head->next = NULL;
}

void	rb(t_stack *stacks)
{
	t_list	**b;
	t_list	*head;

	b = stacks->b;
	if (!(*b) || !((*b)->next))
		return ;
	head = *b;
	*b = head->next;
	(*b)->prev = NULL;
	ft_lstadd_back(b, head);
	head->next = NULL;
}

void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
}
