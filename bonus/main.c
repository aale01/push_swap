/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:05:42 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/27 21:34:37 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	stacks;

	if (argc == 1)
		return (0);
	if (!ft_init_stacks(&stacks, argc - 1, argv))
		ft_error(&stacks);
	if (!ft_read_cmds(&stacks))
		ft_error(&stacks);
	if (!ft_execute_cmds(&stacks))
		ft_error(&stacks);
	ft_check_sort(&stacks);
	ft_close(&stacks);
	return (EXIT_SUCCESS);
}
