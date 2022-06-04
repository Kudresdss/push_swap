/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:21:54 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/24 23:01:55 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header_bonus.h"

int	ft_check(char	*buf, t_gnl	*st)
{
	st->i = 0;
	while (buf[st->i])
	{
		if (buf[st->i] == '\n')
		{
			if (st->i + 1 == ft_strlen(buf))
				return (1);
			else
				return (2);
		}
		st->i++;
	}
	return (0);
}

char	*ft_chop(char	*str1, char	*end, t_gnl	*st)
{
	int		x;

	st->str = NULL;
	x = ft_check(end, st);
	if (x > 0)
	{
		if (x == 1)
			str1 = ft_sub(end, 0, st->i + 1, 1);
		if (x == 2)
		{
			str1 = ft_sub(end, 0, st->i + 1, 0);
			st->str = ft_sub(end, st->i + 1, ft_strlen(end) - st->i, 1);
		}
		st->line = 0;
	}
	else
		str1 = ft_join(str1, end, 1);
	return (str1);
}

char	*ft_work(char	*buf, char **str1, char	*end, t_gnl	*st)
{
	while (st->chr && st->line)
	{
		st->chr = read(st->fd, buf, 1);
		buf[st->chr] = '\0';
		if (!ft_strlen(buf) || !st->chr)
			break ;
		if (ft_check(buf, st) == 2)
		{
			*str1 = ft_join(*str1, ft_sub(buf, 0, st->i + 1, 0), 1);
			end = ft_sub(buf, st->i + 1, ft_strlen(buf) - st->i, 0);
		}
		else if (!end)
			*str1 = ft_join(*str1, buf, 0);
		if (buf[st->i] == '\n')
			break ;
	}
	return (end);
}

int	get_next_line(int fd_0, t_stack	***st)
{
	t_gnl		stc;
	char		buf[2];
	static char	*end;
	char		*str1;

	if (read(fd_0, NULL, 0) < 0)
		return (0);
	str1 = NULL;
	stc.chr = 1;
	stc.line = 1;
	stc.fd = fd_0;
	if (end)
	{
		str1 = ft_chop(str1, end, &stc);
		end = stc.str;
	}
	end = ft_work(buf, &str1, end, &stc);
	if (stc.chr)
		stc.chr = do_action(str1, st);
	free(str1);
	return (stc.chr);
}
