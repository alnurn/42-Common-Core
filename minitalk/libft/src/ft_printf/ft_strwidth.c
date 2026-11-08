/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:11:15 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/14 20:46:08 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest)
		return ;
	if (src)
	{
		while (i < n && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	while (i < n)
	{
		dest[i] = ' ';
		i++;
	}
}

void	ft_strwidth(t_strlen	*str, t_struct	*data, char c)
{
	char	*temp;

	temp = str->str;
	if (data->num_width > str->len)
	{
		str->str = (char *) malloc((data->num_width + 1) * sizeof(char));
		if (!str->str)
		{
			str->len = 0;
			return ;
		}
		str->str[data->num_width] = '\0';
		if (!data->minus)
		{
			ft_memset((void *) str->str, (int) c, (size_t) data->num_width);
			ft_revstrcpy(str, data->num_width, (const char *) temp, c);
		}
		else
			ft_strncpy(str->str, (const char *) temp, (size_t) data->num_width);
		str->len = data->num_width;
		free(temp);
	}
}
