/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:31:44 by alebe             #+#    #+#             */
/*   Updated: 2025/09/09 20:22:10 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*head;

	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	head = *lst;
	while (head->next)
		head = head->next;
	head->next = new_node;
	new_node->prev = head;
}
