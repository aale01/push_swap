/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:53:42 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/22 15:12:48 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *stacks)
{
	t_list	**a;
	t_list	*head;
	t_list	*next;

	a = stacks->a;
	if (!(*a) || !((*a)->next))
		return ;
	head = (*a)->next;
	next = *a;
	next->next = head->next;
	head->next = next;
	head->prev = NULL;
	next->prev = head;
	if (next->next)
		next->next->prev = next;
	*a = head;
}

void	sb(t_stack *stacks)
{
	t_list	**b;
	t_list	*head;
	t_list	*next;

	b = stacks->b;
	if (!(*b) || !((*b)->next))
		return ;
	head = (*b)->next;
	next = *b;
	next->next = head->next;
	head->next = next;
	head->prev = NULL;
	next->prev = head;
	if (next->next)
		next->next->prev = next;
	*b = head;
}

void	ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
}
