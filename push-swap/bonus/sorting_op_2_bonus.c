/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_op_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:52:11 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/24 21:31:47 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header_bonus.h"

void	do_ra(t_stack	**head)
{
	*head = (*head)->next;
	return ;
}

void	do_rb(t_stack	**head)
{
	*head = (*head)->next;
	return ;
}

void	do_rra(t_stack	**head)
{
	*head = (*head)->prev;
	return ;
}

void	do_rrb(t_stack	**head)
{
	*head = (*head)->prev;
	return ;
}
