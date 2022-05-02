/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:57:41 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/24 21:31:29 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header_bonus.h"

void	find_mn_mx_int(t_stack	*st_a, int	*tmp, size_t size)
{
	st_a->i = 0;
	while (st_a->i < size)
	{
		st_a->y = 0;
		st_a->min = tmp[st_a->i];
		while (tmp[st_a->i] <= tmp[st_a->y] && st_a->y < size)
			st_a->y++;
		if (st_a->y == size)
			break ;
		st_a->i++;
	}
	st_a->i = 0;
	while (st_a->i < size)
	{
		st_a->y = 0;
		st_a->max = tmp[st_a->i];
		while (tmp[st_a->i] >= tmp[st_a->y] && st_a->y < size)
			st_a->y++;
		if (st_a->y == size)
			break ;
		st_a->i++;
	}
	return ;
}

void	int_swap(int	*arr, int	*l, int	*r)
{
	int	tmp;

	tmp = arr[*l];
	arr[*l] = arr[*r];
	arr[*r] = tmp;
	*l += 1;
	if (*r > 0)
		*r -= 1;
}

void	quick_sort(int	*arr, int start, int end)
{
	int	l;
	int	r;
	int	median;

	l = start;
	r = end;
	median = arr[start + (end - start) / 2];
	while (l <= r)
	{
		while (arr[l] < median)
			l++;
		while (arr[r] > median)
			r--;
		if (l <= r)
			int_swap(arr, &l, &r);
	}
	if (start < r)
		quick_sort(arr, start, r);
	if (end > l)
		quick_sort(arr, l, end);
}

void	insert_index(t_stack	*head, int	*tmp, int size)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = head;
	while (i < size)
	{
		if (current->val == tmp[i])
		{
			current->index = i;
			i++;
		}
		else
			current = current->next;
	}
}
