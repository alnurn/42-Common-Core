/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:45:32 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 21:47:46 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char	*s, char c)
{
	int		flag;
	size_t	count;

	if (!s)
		return (0);
	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			flag = 1;
			count++;
		}
		if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static void	ft_freedst(char	**dst)
{
	size_t	i;

	i = 0;
	while (dst[i])
	{
		free(dst[i]);
		i++;
	}
	free(dst);
}

static char	**ft_build(char	**dst, char const	*s, char c)
{
	size_t	i;
	size_t	icount;
	size_t	start;

	i = 0;
	icount = 0;
	start = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		dst[icount] = ft_substr(s, start, i - start);
		if (!dst[icount])
		{
			ft_freedst(dst);
			return (NULL);
		}
		icount++;
	}
	return (dst);
}

char	**ft_split(char const	*s, char c)
{
	char	**dst;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	dst = (char **) malloc((count + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	dst = ft_build(dst, s, c);
	if (!dst)
		return ((char **) ft_calloc(1, 1));
	dst[count] = NULL;
	return (dst);
}
