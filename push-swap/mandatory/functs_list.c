/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:27:51 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/21 20:41:22 by ymirna           ###   ########.fr       */
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