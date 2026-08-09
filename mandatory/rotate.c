/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:02:33 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/10 04:35:02 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_lstadd_back(stacks->cmds, ft_lstnew(ft_strdup("ra")));
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
	ft_lstadd_back(stacks->cmds, ft_lstnew(ft_strdup("rb")));
}

void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
	ft_lstadd_back(stacks->cmds, ft_lstnew(ft_strdup("rr")));
}
