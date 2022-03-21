/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:25:08 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/21 18:45:22 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header.h"

size_t	ft_strlen(const char	*s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t	len)
{
	char	*str;
	size_t	i;
	size_t	lens;

	i = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (len > lens)
		len = lens;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		if (start >= lens)
			break ;
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}

long	ft_atoi(t_stack	*st_a, const char	*str)
{
	unsigned long long	s;

	st_a->y = 0;
	st_a->ng = 1;
	s = 0;
	while (str[st_a->y] == '\t' || str[st_a->y] == '\n' || str[st_a->y] == '\v'
		|| str[st_a->y] == '\f' || str[st_a->y] == '\r' || str[st_a->y] == ' ')
		st_a->y++;
	if (str[st_a->y] == '-' || str[st_a->y] == '+')
	{
		if (str[st_a->y] == '-')
			st_a->ng *= -1;
		st_a->y += 1;
	}
	while ('0' <= str[st_a->y] && str[st_a->y] <= '9')
		s = s * 10 + (str[st_a->y++] - '0');
	return (s * st_a->ng);
}

int	ft_if_nmb(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || '9' < str[i]) && str[i] != ' ' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}
