/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:01:55 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/21 18:45:33 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header.h"

void	print_index(t_stack	*head)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = head;
	while (current->next != head)
	{
		printf("val = %d, index = %d\n", current->val, current->index);
		current = current->next;
	}
	printf("val = %d, index = %d\n", current->val, current->index);
}

//на убой

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
	median = arr[start + (end - start)/2];
	while (l <= r)
	{
		while(arr[l] < median)
			l++;
		while(arr[r] > median)
			r--;
		if (l <= r)
			int_swap(arr, &l, &r);
	}
	if (start < r)
		quick_sort(arr, start, r);
	if (end > l)
		quick_sort(arr, l, end);
}

void	insert_index(t_stack	*head, int	*tmp, int	size)
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
	print_index(head);
}

void	sort_index(t_stack	*head, int	*tmp, int	size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		printf("%d\n", tmp[i]);
		i++;
	}
	quick_sort(tmp, 0, size - 1);
	i = 0;
	write(1, "\n", 1);
	while(i < size)
	{
		printf("%d\n", tmp[i]);
		i++;
	}
	insert_index(head, tmp, size);
}

void	find_mn_mx_int(t_stack	*st_a, int	*tmp, int	size)
{
	int	i;
	int	y;

	i = 0;
	while (i < size)
	{
		y = 0;
		st_a->min = tmp[i];
		while (tmp[i] <= tmp[y] && y < size)
			y++;
		if (y == size)
			break;
		i++;
	}
	i = 0;
	while (i < size)
	{
		y = 0;
		st_a->max = tmp[i];
		while (tmp[i] >= tmp[y] && y < size)
			y++;
		if (y == size)
			break;
		i++;
	}
	return ;
}

int	add_index(t_stack	*st_a, int	size)
{
	t_stack	*current;
	int		*tmp;
	int		i;

	i = 0;
	current = st_a->next;
	printf("size = %d, current->val = %d\n", size, current->val);
	tmp = (int	*)malloc(sizeof(int) * size);
	if (!tmp)
		return (1);
	while(current->next != st_a->next)
	{
		tmp[i] = current->val;
		current = current->next;
		i++;
	}
	tmp[i] = current->val;
	find_mn_mx_int(st_a, tmp, size);
	printf("min = %d, max = %d\n", st_a->min, st_a->max);
	i = 0;
	sort_index(st_a->next, tmp, size);
	free(tmp);
	return (0);
}

int	sorted_stack(t_stack	*head)
{
	t_stack	*current;

	current = head;
	while(current->next != head)
	{
		if (current->val > current->next->val)
			return (1);
		current = current->next;
	}
	return (0);
}

void	push_swap(t_stack	*st_a)
{
	//Не забывай посылать не st_a, а его next!
	if(!sorted_stack(st_a->next))
	{	
		printf("sorted!\n");
		return ;
	}
	if (add_index(st_a, st_a->size))
	{
		write(2, "Error\n", 6);
		return ;
	}
	printf("sorrow! cmon then\n");
	start_sorting(st_a);
	return ;
}
