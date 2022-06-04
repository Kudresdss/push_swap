/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:02:38 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/25 00:01:45 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header_bonus.h"

void	assert_head_ptr(t_stack	*head, t_stack	*head_a, t_stack	*head_b)
{
	t_stack	*current;

	current = head;
	while (current->next != head)
	{
		current->head_a = head_a;
		current->head_b = head_b;
		current = current->next;
	}
	current->head_a = head_a;
	current->head_b = head_b;
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
	do_chck(st_a, st_b, &current_a, &current_b);
}

void	start_sorting(t_stack	*st_a)
{
	t_stack	*st_b;
	t_stack	*current;

	current = st_a->next;
	st_b = (t_stack *)malloc(sizeof(t_stack));
	if (!st_b)
	{
		write(2, "Error\n", 6);
		return ;
	}
	st_b->next = NULL;
	st_b->prev = NULL;
	assert_head_ptr(st_a->next, st_a, st_b);
	sort_high(st_a, st_b);
	free(st_b);
}
