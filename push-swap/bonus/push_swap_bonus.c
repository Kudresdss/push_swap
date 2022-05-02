/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:01:55 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/25 17:00:06 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header_bonus.h"

void	sort_index(t_stack	*head, int	*tmp, int size)
{
	int	i;

	i = 0;
	quick_sort(tmp, 0, size - 1);
	insert_index(head, tmp, size);
}

int	add_index(t_stack	*st_a, int size)
{
	t_stack	*current;
	size_t	size_st;
	int		*tmp;
	int		i;

	i = 0;
	current = st_a->next;
	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (1);
	while (current->next != st_a->next)
	{
		tmp[i] = current->val;
		current = current->next;
		i++;
	}
	tmp[i] = current->val;
	size_st = (size_t)size;
	find_mn_mx_int(st_a, tmp, size_st);
	i = 0;
	sort_index(st_a->next, tmp, size);
	free(tmp);
	return (0);
}

int	sorted_stack(t_stack	*head)
{
	t_stack	*current;

	current = head;
	while (current->next != head)
	{
		if (current->val > current->next->val)
			return (1);
		current = current->next;
	}
	return (0);
}

void	push_swap(t_stack	*st_a)
{
	if (!sorted_stack(st_a->next))
	{
		write(1, "OK\n", 3);
		return ;
	}
	if (add_index(st_a, st_a->size))
	{
		write(2, "Error\n", 6);
		return ;
	}
	start_sorting(st_a);
	return ;
}
