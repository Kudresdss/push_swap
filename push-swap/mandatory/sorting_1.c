/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:02:38 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/21 19:46:26 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header.h"

int	sort_3_status(t_stack	*head)
{
	int l_0;
	int	l_1;
	int	l_2;

	l_0 = head->val;
	l_1 = head->next->val;
	l_2 = head->next->next->val;
	if (l_0 < l_1 && l_1 < l_2)
		return (0);
	else if (l_0 < l_2 && l_2 < l_1)
		return (1);
	else if (l_1 < l_0 && l_0 < l_2)
		return (2);
	else if (l_2 < l_0 && l_0 < l_1)
		return (3);
	else if (l_2 < l_1 && l_1 < l_0)
		return (4);
	else
		return (5);
}

void	sort_3(t_stack	**head)
{
	printf("\nsort_3, l_0 = %d, l_1 = %d, l_2 = %d, status = %d\n\n", (*head)->val, (*head)->next->val, (*head)->next->next->val,  sort_3_status(*head));
	print_list(*head);
	if (sort_3_status(*head) == 0)
		return ;
	else if (sort_3_status(*head) == 1)
	{
		do_rra(head);
		do_sa(head);
		return ;
	}
	else if (sort_3_status(*head) == 2)
	{
		do_sa(head);
		return ;
	}
	else if (sort_3_status(*head) == 3)
	{
		do_rra(head);
		return ;
	}
	else if (sort_3_status(*head) == 4)
	{
		do_sa(head);
		do_rra(head);
		return ;
	}
	do_ra(head);
}

void	sort_medium(t_stack	**current_a, t_stack	*st_a, t_stack	*st_b)
{
	t_stack	*current_b;

	current_b = st_b;
	while ((*current_a)->val != st_a->min)
		do_ra(current_a);
	do_pb(current_a, &current_b);
	if (st_a->size == 5)
	{
		while ((*current_a)->index != 1)
			do_ra(current_a);
		do_pb(current_a, &current_b);
	}
	sort_3(current_a);
	printf("\nlist_a:\n");
	print_list(*current_a);
	printf("\nlist_b:\n");
	print_list(current_b);
	if (st_a->size == 5)
		do_pa(current_a, &current_b, st_b);
	do_pa(current_a, &current_b, st_b);
}

void	assert_head_pointers(t_stack	*head, t_stack	*head_a, t_stack	*head_b)
{
	t_stack	*current;

	current = head;
	while(current->next != head)
	{
		current->head_a = head_a;
		current->head_b = head_b;
		current = current->next;
	}
	current->head_a = head_a;
	current->head_b = head_b;
}

void	start_sorting(t_stack	*st_a)
{
	t_stack	*st_b;
	t_stack	*current = NULL;

	st_b = (t_stack *)malloc(sizeof(t_stack));
	if (!st_b)
	{
		write(2, "Error\n", 6);
		return ;
	}
	st_b->next = NULL;
	st_b->prev = NULL;
	assert_head_pointers(st_a->next, st_a, st_b);
	if (st_a->size <= 5)
	{
		current = st_a->next;
		if (st_a->size == 2)
			do_ra(&current);
		else if (st_a->size == 3)
			sort_3(&current);
		else if (st_a->size > 3)
			sort_medium(&current, st_a, st_b);
	}
	//else
		//sort_high(st_a, st_b);
	print_list(current);
	if (!sorted_stack(current))
		fprintf(stderr, "sorted!\n");
	free(st_b);
}

//СЛЕДИТЬ ЗА ТЕМ, ЧТОБЫ КОГДА ВСЕ ЭЛЕМЕНТЫ ПЕРЕКИДЫВАЮТСЯ, УКАЗАТЕЛИ ХЭДОВ ОБНУЛЯЛИСЬ (иначе они будут указывать на эл-ты в другом стэке)