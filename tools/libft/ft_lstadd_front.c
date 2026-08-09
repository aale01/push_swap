/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:14:16 by alebe             #+#    #+#             */
/*   Updated: 2025/09/01 21:07:54 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *lst;
	new_node->prev = NULL;
	if (*lst)
		(*lst)->prev = new_node;
	*lst = new_node;
}
