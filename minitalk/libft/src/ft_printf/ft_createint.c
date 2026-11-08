/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 22:12:17 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 20:31:47 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_spaceplus(t_strlen	*str, t_struct	*data)
{
	char	*temp;

	temp = str->str;
	str->str = (char *) malloc((str->len + 2) * sizeof(char));
	if (!str->str)
	{
		str->len = 0;
		return ;
	}
	str->str[str->len + 1] = '\0';
	if (data->plus)
		ft_revstrcpy(str, str->len + 1, (const char *) temp, '+');
	if (data->space)
		ft_revstrcpy(str, str->len + 1, (const char *) temp, ' ');
	free(temp);
	str->len++;
}

static void	ft_swap(t_strlen	*str)
{
	char	temp;
	size_t	i;

	i = 0;
	while (str->str[i])
	{
		if (str->str[i] == ' ' || str->str[i] == '-' || str->str[i] == '+')
		{
			temp = str->str[0];
			str->str[0] = str->str[i];
			str->str[i] = temp;
			break ;
		}
		i++;
	}
}

static void	ft_checkset(t_strlen	*str, t_struct	*data, int n)
{
	if (data->plus || data->space)
		ft_spaceplus(str, data);
	if ((n < 0 || data->plus || data->space)
		&& ((str->len - 1) < data->dot_precision))
	{
		ft_precision(str, data->dot_precision + 1);
		ft_swap(str);
	}
	else if (n >= 0 && !data->plus && !data->space
		&& (str->len < data->dot_precision))
		ft_precision(str, data->dot_precision);
	if (data->num_width && data->zero)
	{
		ft_strwidth(str, data, '0');
		ft_swap(str);
	}
	else if (data->num_width && !data->zero)
		ft_strwidth(str, data, ' ');
}

t_strlen	ft_createint(int n, t_struct	*data)
{
	t_strlen	str;

	str = ft_itoastrlen(n);
	if (!n && data->dot && !data->dot_precision)
	{
		free(str.str);
		str.str = NULL;
		str.len = 0;
	}
	if (n < 0)
	{
		data->plus = 0;
		data->space = 0;
	}
	ft_checkset(&str, data, n);
	return (str);
}
