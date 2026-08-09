/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:53:42 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/10 04:35:02 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_lstadd_back(stacks->cmds, ft_lstnew(ft_strdup("sa")));
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
	ft_lstadd_back(stacks->cmds, ft_lstnew(ft_strdup("sb")));
}

void	ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
	ft_lstadd_back(stacks->cmds, ft_lstnew(ft_strdup("ss")));
}
