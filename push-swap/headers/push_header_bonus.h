/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_header_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:59:01 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/25 00:04:52 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_HEADER_BONUS_H
# define PUSH_HEADER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	size_t			i;
	size_t			y;
	int				x;
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

typedef struct s_gnl
{
	int		line;
	int		fd;
	char	*str;
	size_t	chr;
	size_t	i;
}	t_gnl;

int		get_next_line(int fd_0, t_stack	***st);
size_t	ft_strlen(const char	*s);
char	*ft_sub(char *s, unsigned int start, size_t	len, int x);
char	*ft_join(char *s1, char *s2, int x);
long	ft_atoi(t_stack	*stack_a, const char	*str);
int		ft_if_nmb(char	*str);
char	*ft_substr(char const *s, unsigned int start, size_t	len);
int		ft_strncmp(const char	*s1, const char	*s2, int n);
char	**ft_split(char const	*s, char c);
void	push_swap(t_stack	*st_a);
void	int_swap(int	*arr, int	*l, int	*r);
void	quick_sort(int	*arr, int start, int end);
void	insert_index(t_stack	*head, int	*tmp, int size);
void	find_mn_mx_int(t_stack	*st_a, int	*tmp, size_t size_st);
int		sorted_stack(t_stack	*head);
void	start_sorting(t_stack	*st_a);
int		score_r(t_stack	*head, int val);
int		add_list(t_stack	*current, int val);
int		ft_check_doubles(t_stack	*st_a);
int		list_counter(t_stack	*head);
void	free_stack_line(t_stack	*head);
void	free_stack_ring(t_stack	*head);
void	sort_high(t_stack	*st_a, t_stack	*st_b);
void	do_pa(t_stack	**head_a, t_stack	**head_b, t_stack	*st_b);
void	do_pb(t_stack	**head_a, t_stack	**head_b, t_stack	*st_a);
void	do_sa(t_stack	**head);
void	do_sb(t_stack	**head);
void	do_ra(t_stack	**head);
void	do_rb(t_stack	**head);
void	do_rr(t_stack	**head_a, t_stack	**head_b);
void	do_rra(t_stack	**head);
void	do_rrb(t_stack	**head);
int		do_action(char	*act, t_stack	***st);
void	do_chck(t_stack	*st_a, t_stack	*st_b, t_stack	**h_a, t_stack	**h_b);

#endif