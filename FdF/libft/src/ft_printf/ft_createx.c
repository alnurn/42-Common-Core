/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 11:03:38 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 20:41:50 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_revstr(t_strlen	*str, int n, const char *src, char convers)
{
	int	i;

	i = str->len - 1;
	if (!str || !str->str)
		return ;
	n--;
	while (i >= 0)
	{
		str->str[n] = src[i];
		i--;
		n--;
	}
	if (n >= 0 && convers == 'x')
		str->str[n] = 'x';
	else if (n >= 0 && convers == 'X')
		str->str[n] = 'X';
	str->str[0] = '0';
}

static void	ft_sharp(t_strlen	*str, char convers)
{
	char	*temp;

	temp = str->str;
	str->str = (char *) malloc((str->len + 3) * sizeof(char));
	if (!str->str)
	{
		str->len = 0;
		return ;
	}
	str->str[str->len + 2] = '\0';
	ft_revstr(str, str->len + 2, (const char *) temp, convers);
	free(temp);
	str->len += 2;
}

static void	ft_swap(t_strlen	*str)
{
	char	temp;
	size_t	i;

	i = 0;
	while (str->str[i])
	{
		if (str->str[i] == 'x' || str->str[i] == 'X')
		{
			temp = str->str[1];
			str->str[1] = str->str[i];
			str->str[i] = temp;
			break ;
		}
		i++;
	}
}

static void	ft_checksett(t_strlen	*str, t_struct	*data, char convers)
{
	if (data->sharp)
		ft_sharp(str, convers);
	if (data->sharp && (str->len - 2) < data->dot_precision)
	{
		ft_precision(str, data->dot_precision + 2);
		ft_swap(str);
	}
	else if (!data->sharp && str->len < data->dot_precision)
		ft_precision(str, data->dot_precision);
	if (data->num_width && data->zero)
	{
		ft_strwidth(str, data, '0');
		ft_swap(str);
	}
	else if (data->num_width && !data->zero)
		ft_strwidth(str, data, ' ');
}

t_strlen	ft_createx(unsigned int u, char convers, t_struct	*data)
{
	t_strlen	str;

	str = ft_createxx(u, convers);
	if (!u)
		data->sharp = 0;
	if (!u && data->dot && !data->dot_precision)
	{
		free(str.str);
		str.str = NULL;
		str.len = 0;
	}
	ft_checksett(&str, data, convers);
	return (str);
}
