/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:25:08 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/25 16:27:36 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header_bonus.h"

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

int	ft_strncmp(const char	*s1, const char	*s2, int x)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	(void) x;
	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[i] && ss2[i])
	{
		if (ss1[i] == s2[i])
			i++;
		else
			return (ss1[i] - ss2[i]);
	}
	if (x == 1)
		return ((ft_strlen(s1) + 1) - ft_strlen(s2));
	return (0);
}

int	ft_if_nmb(char	*str)
{
	size_t	i;
	size_t	y;
	size_t	z;

	i = 0;
	y = 0;
	z = 0;
	while (str[i])
	{
		if ((str[i] < '0' || '9' < str[i]) && str[i] != ' ' && str[i] != '-')
			return (1);
		else if (str[i] == '-')
			y++;
		else if (str[i] >= '0' && str[i] <= '9')
			z++;
		i++;
	}
	if (y > 1 || z == 0)
		return (1);
	return (0);
}
