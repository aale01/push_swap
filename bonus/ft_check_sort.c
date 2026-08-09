/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:20:39 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/22 15:39:50 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_sort(t_stack *stacks)
{
	t_list	*a;

	if (*stacks->b)
	{
		ft_printf("KO\n");
		return ;
	}
	a = *stacks->a;
	while (a->next)
	{
		if (*(int *)a->content > *(int *)a->next->content)
		{
			ft_printf("KO\n");
			return ;
		}
		a = a->next;
	}
	ft_printf("OK\n");
}
