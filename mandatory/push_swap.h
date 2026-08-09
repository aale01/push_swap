/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:53:30 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/10 04:35:01 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef enum e_bool
{
	False,
	True
}					t_bool;

typedef struct s_stack
{
	t_list	**a;
	t_list	**b;
	t_list	**cmds;
	int		size;
	int		*arr;
	int		num_chunk;
	int		*chunk_size;
}					t_stack;

int		ft_init_stacks(t_stack *stacks, int size, char *argv[]);
void	ft_init_chunks(t_stack *stacks);
void	ft_set_arr(t_stack *stacks);
void	ft_error(t_stack *stacks);
void	ft_close(t_stack *stacks);
void	ft_divide_et_impera(t_stack *stacks);
void	ft_sort_single_chunk(t_stack *stacks);
void	ft_sort_chunk(t_stack *stacks);
void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
void	ra(t_stack *stacks);
void	rb(t_stack *stacks);
void	rr(t_stack *stacks);
void	rra(t_stack *stacks);
void	rrb(t_stack *stacks);
void	rrr(t_stack *stacks);
void	ft_impera(t_stack *stacks);
void	ft_del_cmds(t_list **lst);
void	ft_print_cmd(void *s);

#endif
