/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_op_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:50:12 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/24 21:31:42 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header_bonus.h"

void	do_pa(t_stack	**head_a, t_stack	**head_b, t_stack	*st_b)
{
	t_stack	*push;
	t_stack	*prev_b;
	t_stack	*next_b;

	push = *head_b;
	if (list_counter(*head_b) != 1)
	{
		prev_b = (*head_b)->prev;
		next_b = (*head_b)->next;
		prev_b->next = next_b;
		next_b->prev = prev_b;
		*head_b = next_b;
	}
	else
	{
		*head_b = st_b;
		st_b->next = NULL;
	}
	push->prev = (*head_a)->prev;
	push->next = *head_a;
	(*head_a)->prev->next = push;
	(*head_a)->prev = push;
	*head_a = push;
	return ;
}

void	do_pb_2(t_stack	**head_b, t_stack	**push)
{
	if ((*head_b)->next == NULL)
	{
		(*head_b)->next = *push;
		(*push)->next = *push;
		(*push)->prev = *push;
	}
	else
	{
		(*push)->prev = (*head_b)->prev;
		(*push)->next = *head_b;
		(*head_b)->prev->next = *push;
		(*head_b)->prev = *push;
	}
	*head_b = *push;
}

void	do_pb(t_stack	**head_a, t_stack	**head_b, t_stack	*st_a)
{
	t_stack	*push;
	t_stack	*prev_a;
	t_stack	*next_a;

	push = *head_a;
	if (list_counter(*head_a) != 1)
	{
		prev_a = (*head_a)->prev;
		next_a = (*head_a)->next;
		prev_a->next = next_a;
		next_a->prev = prev_a;
		*head_a = next_a;
	}
	else
	{
		*head_a = st_a;
		st_a->next = NULL;
	}
	do_pb_2(head_b, &push);
	return ;
}

void	do_sa(t_stack	**head)
{
	t_stack	*top;
	t_stack	*swap;
	t_stack	*tmp;
	t_stack	*swap_next;
	t_stack	*prev;

	top = *head;
	swap = (*head)->next;
	swap_next = (*head)->next->next;
	prev = (*head)->prev;
	prev->next = swap;
	swap_next->prev = top;
	top->next = swap_next;
	swap->prev = prev;
	tmp = swap;
	tmp->next = top;
	swap = top;
	swap->prev = tmp;
	top = tmp;
	*head = top;
}

void	do_sb(t_stack	**head)
{
	t_stack	*top;
	t_stack	*swap;
	t_stack	*tmp;
	t_stack	*swap_next;
	t_stack	*prev;

	top = *head;
	swap = (*head)->next;
	swap_next = (*head)->next->next;
	prev = (*head)->prev;
	prev->next = swap;
	swap_next->prev = top;
	top->next = swap_next;
	swap->prev = prev;
	tmp = swap;
	tmp->next = top;
	swap = top;
	swap->prev = tmp;
	top = tmp;
	*head = top;
}
