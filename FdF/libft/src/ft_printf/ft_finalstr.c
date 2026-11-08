/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:16:06 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 20:52:51 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_strlen	ft_createchar(int c, t_struct	*data)
{
	t_strlen	str;

	str.len = 1;
	if (data->num_width > str.len)
		str.len = data->num_width;
	str.str = (char *) malloc((str.len + 1) * sizeof(char));
	if (!str.str)
	{
		str.len = 0;
		return (str);
	}
	str.str[str.len] = '\0';
	if (str.len > 1)
		ft_memset((void *) str.str, (int) ' ', (size_t) str.len);
	if (!data->minus)
		str.str[str.len - 1] = (char) c;
	else
		str.str[0] = (char) c;
	return (str);
}

static t_strlen	ft_createstr(char *string, t_struct	*data)
{
	t_strlen	str;
	char		*temp;

	if (!string && (!data->dot || data->dot_precision >= 6))
		temp = ft_strdup("(null)");
	else
		temp = ft_strdup((const char *) string);
	str.str = temp;
	str.len = (int) ft_strlen((const char *) temp);
	if (data->dot && data->dot_precision < str.len)
	{
		str.len = data->dot_precision;
		str.str = (char *) malloc((str.len + 1) * sizeof(char));
		if (!str.str)
		{
			str.len = 0;
			return (str);
		}
		ft_strlcpy(str.str, (const char *) temp, (size_t) str.len + 1);
		free(temp);
	}
	ft_strwidth(&str, data, ' ');
	return (str);
}

/*returns string according to the flag*/
t_strlen	ft_finalstr(char convers, t_struct	*data, va_list args)
{
	t_strlen	str;

	str.str = NULL;
	str.len = 0;
	if (convers == 'c')
		return (ft_createchar(va_arg(args, int), data));
	else if (convers == 's')
		return (ft_createstr(va_arg(args, char *), data));
	else if (convers == 'p')
		return (ft_createaddr(va_arg(args, void *), data));
	else if (convers == 'd' || convers == 'i')
		return (ft_createint(va_arg(args, int), data));
	else if (convers == 'u')
		return (ft_createu(va_arg(args, unsigned int), data));
	else if (convers == 'x' || convers == 'X')
		return (ft_createx(va_arg(args, unsigned int), convers, data));
	else if (convers == '%')
		return (ft_createchar('%', data));
	return (str);
}
