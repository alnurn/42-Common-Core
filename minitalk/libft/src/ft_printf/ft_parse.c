/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:37:08 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 21:04:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnumber(char	*substr)
{
	int		i;
	int		start;
	int		value;
	char	*num;

	i = 0;
	value = 0;
	if (substr[i] && ft_isdigit((int) substr[i]))
	{
		start = i;
		while (substr[i] && ft_isdigit((int) substr[i]))
			i++;
		if (i != start)
			i--;
		num = ft_substr((const char *) substr,
				(unsigned int) start, (size_t) i - start + 1);
		value = ft_atoi((const char *) num);
		free(num);
	}
	return (value);
}

static void	ft_putnum(t_struct	*data, char	*substr, char convers)
{
	int	i;

	i = 1;
	if (!data || !substr || convers == '%')
		return ;
	while (substr[i] && ft_isformatflag(substr[i]))
		i++;
	data->num_width = ft_putnumber(&substr[i]);
	i = 0;
	while (substr[i])
	{
		if (substr[i] == '.')
		{
			i++;
			break ;
		}
		i++;
	}
	if (data->dot)
		data->dot_precision = ft_putnumber(&substr[i]);
}

static void	ft_doublecheck(t_struct	*data, char	*substr, char convers)
{
	if (data->minus == 1 || data->dot == 1)
		data->zero = 0;
	if (data->plus == 1)
		data->space = 0;
	ft_putnum(data, substr, convers);
}

void	ft_parse(t_struct	*data, char	*substr, char convers)
{
	size_t	i;

	i = 0;
	while (substr[i] && convers != '%')
	{
		if (substr[i] == '+' && (convers == 'i' || convers == 'd'))
			data->plus = 1;
		if (substr[i] == ' ' && (convers == 'i' || convers == 'd'))
			data->space = 1;
		if (substr[i] == '-')
			data->minus = 1;
		if (substr[i] == '.' && convers != 'c' && convers != 'p')
			data->dot = 1;
		if (i > 0)
		{
			if (!ft_isdigit((int) substr[i - 1]) && substr[i] == '0'
				&& (convers != 's' && convers != 'c' && convers != 'p'))
				data->zero = 1;
		}
		if (substr[i] == '#' && (convers == 'x' || convers == 'X'))
			data->sharp = 1;
		i++;
	}
	ft_doublecheck(data, substr, convers);
}
