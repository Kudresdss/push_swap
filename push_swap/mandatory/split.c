/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:21:26 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/22 18:41:25 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_header.h"

static size_t	ft_words(char const	*s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
				i++;
			j++;
		}
	}
	return (j);
}

static void	ft_freeall(char **sttr, size_t	words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(sttr[i]);
		i++;
	}
	free(sttr);
}

static char	**ft_strprs(char	**sttr, char const	*s, char c, size_t	words)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (j < words && s[i])
	{
		len = 0;
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
			{
				len++;
				i++;
			}
			sttr[j] = ft_substr(s, i - len, len);
			if (!sttr)
				ft_freeall(sttr, j);
			j++;
		}
	}
	return (sttr);
}

char	**ft_split(char const	*s, char c)
{
	char	**sttr;
	size_t	words;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_words(s, c);
	sttr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!sttr)
		return (NULL);
	sttr = ft_strprs(sttr, s, c, words);
	if (!sttr)
		return (NULL);
	sttr[words] = NULL;
	return (sttr);
}
