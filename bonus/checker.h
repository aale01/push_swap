/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:03:08 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/27 21:34:38 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	t_list	**a;
	t_list	**b;
	t_list	**cmds;
}					t_stack;

int		ft_init_stacks(t_stack *stacks, int size, char *argv[]);
void	ft_error(t_stack *stacks);
void	ft_close(t_stack *stacks);
int		ft_read_cmds(t_stack *stacks);
int		ft_execute_cmds(t_stack *stacks);
void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	ss(t_stack *stacks);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
void	ra(t_stack *stacks);
void	rb(t_stack *stacks);
void	rr(t_stack *stacks);
void	rra(t_stack *stacks);
void	rrb(t_stack *stacks);
void	rrr(t_stack *stacks);
void	ft_check_sort(t_stack *stacks);

#endif
