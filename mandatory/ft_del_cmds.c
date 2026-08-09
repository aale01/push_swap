/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abecucci <abecucci@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:35:22 by abecucci          #+#    #+#             */
/*   Updated: 2025/09/10 04:35:02 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_match_list(t_list *cmd1)
{
	t_list	*cmd2;

	cmd2 = cmd1->next;
	if (!ft_memcmp(cmd1->content, "sa", 3)
		&& !ft_memcmp(cmd2->content, "sa", 3))
		return (1);
	else if (!ft_memcmp(cmd1->content, "pa", 3)
		&& !ft_memcmp(cmd2->content, "pb", 3))
		return (1);
	else if (!ft_memcmp(cmd1->content, "pb", 3)
		&& !ft_memcmp(cmd2->content, "pa", 3))
		return (1);
	else if (!ft_memcmp(cmd1->content, "ra", 3)
		&& !ft_memcmp(cmd2->content, "rra", 4))
		return (1);
	else if (!ft_memcmp(cmd1->content, "rra", 4)
		&& !ft_memcmp(cmd2->content, "ra", 3))
		return (1);
	else if (!ft_memcmp(cmd1->content, "rb", 3)
		&& !ft_memcmp(cmd2->content, "rrb", 4))
		return (1);
	else if (!ft_memcmp(cmd1->content, "rrb", 4)
		&& !ft_memcmp(cmd2->content, "rb", 3))
		return (1);
	return (0);
}

static char	*ft_match_both_lists(t_list *cmd1)
{
	t_list	*cmd2;

	cmd2 = cmd1->next;
	if ((!ft_memcmp(cmd1->content, "sa", 3)
			&& !ft_memcmp(cmd2->content, "sb", 3))
		|| (!ft_memcmp(cmd1->content, "sb", 3)
			&& !ft_memcmp(cmd2->content, "sa", 3)))
		return ("ss");
	else if ((!ft_memcmp(cmd1->content, "ra", 3)
			&& !ft_memcmp(cmd2->content, "rb", 3))
		|| (!ft_memcmp(cmd1->content, "rb", 3)
			&& !ft_memcmp(cmd2->content, "ra", 3)))
		return ("rr");
	else if ((!ft_memcmp(cmd1->content, "rra", 3)
			&& !ft_memcmp(cmd2->content, "rrb", 3))
		|| (!ft_memcmp(cmd1->content, "rrb", 3)
			&& !ft_memcmp(cmd2->content, "rra", 3)))
		return ("rrr");
	else
		return (NULL);
}

static t_list	*handle_match(t_list **lst, t_list *cmd1)
{
	t_list	*head;
	t_list	*cmd2;
	t_list	*next;

	cmd2 = cmd1->next;
	next = cmd2->next;
	if (!cmd1->prev)
		*lst = cmd2->next;
	if (cmd1->prev)
		head = cmd1->prev;
	else
		head = *lst;
	if (head)
		head->next = next;
	if (next)
		next->prev = head;
	ft_lstdelone(cmd1, free);
	ft_lstdelone(cmd2, free);
	return (head);
}

static	t_list	*ft_handle_double_match(t_list *cmd1, char *str_cmd)
{
	t_list	*head;
	t_list	*cmd2;
	t_list	*next;

	cmd2 = cmd1->next;
	if (cmd1->prev)
		head = cmd1->prev;
	else
		head = cmd1;
	next = cmd2->next;
	cmd1->next = next;
	if (next)
		next->prev = cmd1;
	ft_lstdelone(cmd2, free);
	free(cmd1->content);
	cmd1->content = ft_strdup(str_cmd);
	return (head);
}

void	ft_del_cmds(t_list **lst)
{
	char	*option;
	t_list	*cmds;

	if (!lst || !*lst)
		return ;
	cmds = *lst;
	while (cmds && cmds->next)
	{
		option = ft_match_both_lists(cmds);
		if (option)
			cmds = ft_handle_double_match(cmds, option);
		else if (ft_match_list(cmds))
			cmds = handle_match(lst, cmds);
		else
			cmds = cmds->next;
	}
}
