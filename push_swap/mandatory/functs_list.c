/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:27:51 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/24 19:44:29 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header.h"

int	list_counter(t_stack	*head)
{
	t_stack	*current;
	int		i;

	i = 1;
	current = head;
	while (current->next != head)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	free_stack_line(t_stack	*head)
{
	t_stack	*current;

	if (head->next != NULL)
	{
		current = head->next;
		while (current->next != NULL)
			current = current->next;
		while (current != head)
		{
			current = current->prev;
			free(current->next);
		}
	}
	else
		current = head;
	free(current);
	return ;
}

void	free_stack_ring(t_stack	*head)
{
	t_stack	*current;

	if (head->next != head)
	{
		current = head->next;
		while (current != head)
		{
			current = current->next;
			free(current->prev);
		}
	}
	free(head);
	return ;
}

int	add_list(t_stack	*current, int val)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (1);
	list->val = val;
	list->next = NULL;
	list->prev = current;
	current->next = list;
	return (0);
}

int	ft_check_doubles(t_stack	*st_a)
{
	t_stack	*current;
	int		val;

	current = st_a->prev;
	val = st_a->val;
	while (current->prev != NULL)
	{
		if (val == current->val)
			return (1);
		current = current->prev;
	}
	return (0);
}
