/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:20:17 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/10 04:35:02 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stacks)
{
	t_list	*head;

	if (!*(stacks->b))
		return ;
	head = *(stacks->b);
	*(stacks->b) = head->next;
	if (head->next)
		(*stacks->b)->prev = NULL;
	ft_lstadd_front(stacks->a, head);
	ft_lstadd_back(stacks->cmds, ft_lstnew(ft_strdup("pa")));
}

void	pb(t_stack *stacks)
{
	t_list	*head;

	if (!*(stacks->a))
		return ;
	head = *(stacks->a);
	*(stacks->a) = head->next;
	if (head->next)
		(*stacks->a)->prev = NULL;
	ft_lstadd_front(stacks->b, head);
	ft_lstadd_back(stacks->cmds, ft_lstnew(ft_strdup("pb")));
}
