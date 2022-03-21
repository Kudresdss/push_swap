/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:38:11 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/21 18:55:47 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header.h"

int	print_list(t_stack	*head)
{
	t_stack	*current;

	current = head;
	while (current->next != head)
	{
		printf("val = %d\n", current->val);
		current = current->next;
	}
	printf("val = %d\n\nnext round:\n", current->val);
	current = current->next;
	while (current->next != head)
	{
		printf("val = %d\n", current->val);
		current = current->next;
	}
	printf("val = %d\n\nend ringed list\n\n", current->val);
	// printf("val = %d\n", current->next->val);
	// printf("val = %d\n", current->next->next->val);
	// printf("val = %d\n\n", current->next->next->next->val);
	// printf("val = %d\n", current->next->next->next->next->val);
	// printf("val = %d\n", current->next->next->next->next->next->val);
	// printf("val = %d\n\n", current->next->next->next->next->next->next->val);
	return (0);
}

//на убой

int	add_list(t_stack	*current, int	val)
{
	t_stack	*list;

	list = (t_stack	*)malloc(sizeof(t_stack));
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

int	init_lists(t_stack	**current, int	*to_int, size_t	i, int	*size)
{
	size_t	y;
	
	y = 0;
	while(y < i)
	{
		//printf("%d\n", to_int[y]);
		if (add_list(*current, to_int[y]))
		{
			free(to_int);
			return (1);
		}
		*current = (*current)->next;
		*size += 1;
		y++;
	}
	free(to_int);
	if (ft_check_doubles(*current))
		return (1);
	return (0);
}

static int	*ft_to_int(t_stack	*st_a, char	*av)
{
	char	**tmp;
	long	to_long;
	int		*to_int;

	st_a->i = 0;
	if (!ft_if_nmb(av))
	{
		tmp = ft_split(av, ' ');
		while(tmp[st_a->i])
			st_a->i++;
		to_int = (int	*)malloc(sizeof(int) * (st_a->i + 1));
		if (!to_int)
			return(NULL);
		st_a->i = 0;
		while(tmp[st_a->i])
		{
			to_long = ft_atoi(st_a, tmp[st_a->i]);
			if (to_long > INT_MAX || INT_MIN > to_long)
			{
				free(to_int);
				free(tmp[st_a->i]);
				free(tmp);
				return (NULL);
			}
			to_int[st_a->i] = (int)to_long;
			//printf("i = %zu , int = %d\n", st_a->i, to_int[st_a->i]);
			free(tmp[st_a->i]);
			st_a->i++;
		}
		free(tmp);
	}
	else
		to_int = NULL;
	return(to_int);
}

void	free_stack_ring(t_stack	*head)
{
	t_stack	*current;

	if(head->next != head)
	{
		current = head->next;
		while(current != head)
		{
			current = current->next;
			free(current->prev);
		}
	}
	free(head);
	return ;
}

void	free_stack_line(t_stack	*head)
{
	t_stack	*current;

	if (head->next != NULL)
	{
		current = head->next;
		while(current->next->next != NULL)
			current = current->next;
		while(current != head)
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

int	main(int ac, char	**av)
{
	t_stack	*st_a;
	t_stack	*current;
	size_t	i;
	int		*to_int;

	st_a = (t_stack *)malloc(sizeof(t_stack));
	if (!st_a)
		return (1);
	st_a->size = 0;
	st_a->next = NULL;
	st_a->prev = NULL;
	current = st_a;
	i = 1;
	if (ac < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (av[i])
	{
		to_int = ft_to_int(st_a, av[i]);
		if (!to_int)
		{
			free_stack_line(st_a);
			write(2, "Error\n", 6);
			fprintf(stderr, "I sleep in to_int");
			sleep(120);
			return (2);
		}
		if (init_lists(&current, to_int, st_a->i, &(st_a->size)))
		{
			free_stack_line(st_a);
			write(2, "Error\n", 6);
			fprintf(stderr, "I sleep in init");
			sleep(120);
			return (3);
		}
		i++;
	}
	current->next = st_a->next;
	st_a->next->prev = current;
	printf("0 = ok print, 1 = ko: %d\n", print_list(st_a->next));
	printf("size = %d\n", st_a->size);
	if (st_a->size > 1)
		push_swap(st_a);
	free_stack_ring(current->next);
	free(st_a);
	fprintf(stderr, "I sleep in the end\n");
	sleep(120);
	return (0);
}