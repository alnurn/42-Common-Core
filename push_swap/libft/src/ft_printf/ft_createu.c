/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 09:49:53 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 13:23:55 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(unsigned int u, char	*dst, int len)
{
	const char	*s;

	s = "0123456789";
	if (u > DEC_BASE - 1)
		ft_putnbr(u / DEC_BASE, dst, len - 1);
	dst[len] = s[u % DEC_BASE];
}

static t_strlen	ft_createuint(unsigned int u)
{
	t_strlen	str;

	str.len = ft_numlenu(u, DEC_BASE);
	str.str = (char *) malloc((str.len + 1) * sizeof(char));
	if (!str.str)
	{
		str.len = 0;
		return (str);
	}
	str.str[str.len] = '\0';
	ft_putnbr(u, str.str, str.len - 1);
	return (str);
}

t_strlen	ft_createu(unsigned int u, t_struct	*data)
{
	t_strlen	str;

	str = ft_createuint(u);
	if (!u && data->dot && !data->dot_precision)
	{
		free(str.str);
		str.str = NULL;
		str.len = 0;
	}
	if (str.len < data->dot_precision)
		ft_precision(&str, data->dot_precision);
	if (data->num_width && data->zero)
		ft_strwidth(&str, data, '0');
	else if (data->num_width && !data->zero)
		ft_strwidth(&str, data, ' ');
	return (str);
}
