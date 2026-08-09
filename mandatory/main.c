/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:53:33 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/21 21:54:56 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stacks;

	if (argc == 1)
		return (0);
	if (!ft_init_stacks(&stacks, argc - 1, argv))
		ft_error(&stacks);
	ft_divide_et_impera(&stacks);
	ft_del_cmds(stacks.cmds);
	ft_lstiter(*stacks.cmds, ft_print_cmd);
	ft_close(&stacks);
	return (EXIT_SUCCESS);
}
