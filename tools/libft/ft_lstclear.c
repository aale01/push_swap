/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:09:46 by alebe             #+#    #+#             */
/*   Updated: 2025/09/10 04:28:48 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		head = *lst;
		*lst = (*lst)->next;
		if (head->content)
			del(head->content);
		free(head);
	}
	*lst = NULL;
}
