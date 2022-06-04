/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:11:42 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/24 15:09:17 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header.h"

void	butter_placement(t_stack	*st_a, t_stack	**h_a, t_stack	**head_b)
{
	int	cnt;
	int	med;

	cnt = 0;
	med = 0.0375 * st_a->size + 11.25;
	while (cnt < st_a->size)
	{
		if ((*h_a)->index <= cnt && (*h_a)->index != st_a->size - 1)
		{
			do_pb(h_a, head_b, st_a);
			do_rb(head_b);
			cnt++;
		}
		else if ((*h_a)->index <= cnt + med && (*h_a)->index != st_a->size - 1)
		{
			do_pb(h_a, head_b, st_a);
			cnt++;
		}
		else if (cnt == st_a->size - 1)
			break ;
		else
			do_ra(h_a);
	}
	return ;
}

int	score_r(t_stack	*head, int index)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = head;
	while (current->next != head)
	{
		if (current->index == index)
			break ;
		i++;
		current = current->next;
	}
	return (i);
}

int	score_rr(t_stack	*head, int index)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = head;
	while (current->prev != head)
	{
		if (current->index == index)
			break ;
		i++;
		current = current->prev;
	}
	return (i);
}

void	sort_to_a(t_stack	**st, t_stack	**head_a, t_stack	**head_b)
{
	int		i;

	i = st[0]->size - 2;
	while (i >= 0)
	{
		if (score_r(*head_b, i) < score_rr(*head_b, i))
		{
			while ((*head_b)->index != i)
				do_rb(head_b);
			do_pa(head_a, head_b, st[1]);
			i--;
		}
		else
		{
			while ((*head_b)->index != i)
				do_rrb(head_b);
			do_pa(head_a, head_b, st[1]);
			i--;
		}
	}
}

void	sort_high(t_stack	*st_a, t_stack	*st_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_stack	*st[2];

	st[0] = st_a;
	st[1] = st_b;
	current_a = st_a->next;
	current_b = st_b;
	butter_placement(st_a, &current_a, &current_b);
	sort_to_a(st, &current_a, &current_b);
}
