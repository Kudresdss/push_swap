/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:38:53 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/21 19:46:38 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_HEADER_H
# define PUSH_HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_stack
{
	size_t			i;
	size_t			y;
	int				ng;
	int				val;
	int				min;
	int				max;
	int				size;
	int				index;
	struct s_stack	*head_a;
	struct s_stack	*head_b;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

size_t	ft_strlen(const char	*s);
long	ft_atoi(t_stack	*stack_a, const char	*str);
int		ft_if_nmb(char	*str);
char	*ft_substr(char const *s, unsigned int start, size_t	len);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
char	**ft_split(char const	*s, char	c);
void	push_swap(t_stack	*st_a);
int		print_list(t_stack	*head);
int		sorted_stack(t_stack	*head);
void	start_sorting(t_stack	*st_a);
int		list_counter(t_stack	*head);
void	do_pa(t_stack	**head_a, t_stack	**head_b, t_stack	*st_b);
void	do_pb(t_stack	**head_a, t_stack	**head_b);
void	do_sa(t_stack	**head);
void	do_sb(t_stack	**head);
void	do_ra(t_stack	**head);
void	do_rb(t_stack	**head);
void	do_rr(t_stack	**head_a, t_stack	**head_b);
void	do_rra(t_stack	**head);
void	do_rrb(t_stack	**head);

#endif