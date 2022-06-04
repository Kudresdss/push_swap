/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_op_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:52:11 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/24 19:47:16 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header.h"

void	do_ra(t_stack	**head)
{
	*head = (*head)->next;
	write(1, "ra\n", 3);
	return ;
}

void	do_rb(t_stack	**head)
{
	*head = (*head)->next;
	write(1, "rb\n", 3);
	return ;
}

void	do_rra(t_stack	**head)
{
	*head = (*head)->prev;
	write(1, "rra\n", 4);
	return ;
}

void	do_rrb(t_stack	**head)
{
	*head = (*head)->prev;
	write(1, "rrb\n", 4);
	return ;
}
