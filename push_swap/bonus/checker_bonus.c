/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:54:19 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/25 16:57:41 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header_bonus.h"

int	init_lists(t_stack	**current, int	*to_int, size_t	i, int	*size)
{
	size_t	y;

	y = 0;
	while (y < i)
	{
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

void	lg_to_int(long	*to_long, t_stack	*st_a, char	***tmp, int	**to_int)
{
	*to_long = ft_atoi(st_a, (*tmp)[st_a->i]);
	if (*to_long > INT_MAX || INT_MIN > *to_long)
	{
		free(*to_int);
		free((*tmp)[st_a->i]);
		free(*tmp);
		return ;
	}
	(*to_int)[st_a->i] = (int)*to_long;
	free((*tmp)[st_a->i]);
	st_a->i++;
}

int	*ft_to_int(t_stack	*st_a, char	*av)
{
	char	**tmp;
	long	to_long;
	int		*to_int;

	st_a->i = 0;
	if (!ft_if_nmb(av) && ft_strlen(av))
	{
		tmp = ft_split(av, ' ');
		while (tmp[st_a->i])
			st_a->i++;
		to_int = (int *)malloc(sizeof(int) * (st_a->i + 1));
		if (!to_int)
			return (NULL);
		st_a->i = 0;
		while (tmp[st_a->i])
		{
			lg_to_int(&to_long, st_a, &tmp, &to_int);
			if (to_long > INT_MAX || INT_MIN > to_long)
				return (NULL);
		}
		free(tmp);
	}
	else
		to_int = NULL;
	return (to_int);
}

int	main_cycle(t_stack	*st_a, t_stack	**current, char	**av)
{
	size_t	i;
	int		*to_int;

	i = 1;
	while (av[i])
	{
		to_int = ft_to_int(st_a, av[i]);
		if (!to_int)
		{
			free_stack_line(st_a);
			write(2, "Error\n", 6);
			return (2);
		}
		if (init_lists(current, to_int, st_a->i, &(st_a->size)))
		{
			free_stack_line(st_a);
			write(2, "Error\n", 6);
			return (3);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char	**av)
{
	t_stack	*st_a;
	t_stack	*current;

	st_a = (t_stack *)malloc(sizeof(t_stack));
	if (!st_a)
		return (1);
	st_a->size = 0;
	st_a->next = NULL;
	st_a->prev = NULL;
	current = st_a;
	if (ac < 2)
	{
		free(st_a);
		return (0);
	}
	st_a->x = main_cycle(st_a, &current, av);
	if (st_a->x)
		return (st_a->x);
	current->next = st_a->next;
	st_a->next->prev = current;
	if (st_a->size > 1)
		push_swap(st_a);
	free_stack_ring(current->next);
	free(st_a);
	return (0);
}
