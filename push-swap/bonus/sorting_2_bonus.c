/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:11:42 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/25 17:02:41 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header_bonus.h"

void	do_chck(t_stack	*st_a, t_stack	*st_b, t_stack	**h_a, t_stack	**h_b)
{
	t_stack	**st[4];

	st[0] = &st_a;
	st[1] = &st_b;
	st[2] = h_a;
	st[3] = h_b;
	while (1)
	{
		if (get_next_line(0, st) == 0)
			break ;
	}
	if (!sorted_stack(*h_a) && !list_counter(*h_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

int	do_action_4(char	*act, t_stack	***st)
{
	if (!ft_strncmp(act, "rr", 2) && ft_strlen(act) <= 3)
	{
		if ((*st[2])->next != NULL)
			do_ra(st[2]);
		if ((*st[3])->next != NULL)
			do_rb(st[3]);
		return (1);
	}
	else if (!ft_strncmp(act, "rrr", 3) && ft_strlen(act) <= 4)
	{
		if ((*st[2])->next != NULL)
			do_rra(st[2]);
		if ((*st[3])->next != NULL)
			do_rrb(st[3]);
		return (1);
	}
	else
		return (0);
}

int	do_action_3(char	*act, t_stack	***st)
{
	if (!ft_strncmp(act, "rra", 3) && ft_strlen(act) <= 4)
	{
		if ((*st[2])->next != NULL)
			do_rra(st[2]);
		return (1);
	}
	else if (!ft_strncmp(act, "rb", 2) && ft_strlen(act) <= 3)
	{
		if ((*st[3])->next != NULL)
			do_rb(st[3]);
		return (1);
	}
	else if (!ft_strncmp(act, "rrb", 3) && ft_strlen(act) <= 4)
	{
		if ((*st[3])->next != NULL)
			do_rrb(st[3]);
		return (1);
	}
	return (do_action_4(act, st));
}

int	do_action_2(char	*act, t_stack	***st)
{
	if (!ft_strncmp(act, "sb", 2) && ft_strlen(act) <= 3)
	{
		if ((*st[3])->next != NULL)
			do_sb(st[3]);
		return (1);
	}
	else if (!ft_strncmp(act, "ss", 2) && ft_strlen(act) <= 3)
	{
		if ((*st[2])->next != NULL)
			do_sa(st[2]);
		if ((*st[3])->next != NULL)
			do_sb(st[3]);
		return (1);
	}
	else if (!ft_strncmp(act, "ra", 2) && ft_strlen(act) <= 3)
	{
		if ((*st[2])->next != NULL)
			do_ra(st[2]);
		return (1);
	}
	return (do_action_3(act, st));
}

int	do_action(char	*act, t_stack	***st)
{
	if (!ft_strncmp(act, "pa", 2) && ft_strlen(act) <= 3)
	{
		if ((*st[3])->next != NULL)
			do_pa(st[2], st[3], *st[1]);
		return (1);
	}
	else if (!ft_strncmp(act, "pb", 2) && ft_strlen(act) <= 3)
	{
		if ((*st[2])->next != NULL)
			do_pb(st[2], st[3], *st[0]);
		return (1);
	}
	else if (!ft_strncmp(act, "sa", 2) && ft_strlen(act) <= 3)
	{
		if ((*st[2])->next != NULL)
			do_sa(st[2]);
		return (1);
	}
	return (do_action_2(act, st));
}
