/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:11:29 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 21:21:56 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*if function has a flag returns pointer to the flag,
 * if not, return end of the string ('/0')*/
static const char	*ft_pointerflag(const char	*s)
{
	const char	*str;
	const char	*start;

	str = "cspdiuxX%";
	start = str;
	s++;
	while (*s)
	{
		while (*str)
		{
			if (*str == *s)
				return (s);
			str++;
		}
		str = start;
		s++;
	}
	return (s);
}

static void	ft_initdata(t_struct	*data)
{
	data->minus = 0;
	data->zero = 0;
	data->dot = 0;
	data->sharp = 0;
	data->space = 0;
	data->plus = 0;
	data->dot_precision = 0;
	data->num_width = 0;
}

/*minus beats zero*/
/*dot beats zero*/
/*plus beats space*/
static int	ft_checkformat(char	*substr, char convers, int len)
{
	int	i;

	i = 0;
	while (substr[i] && ft_isformatflag(substr[i]))
		i++;
	while (substr[i] && ft_isdigit((int) substr[i]))
		i++;
	if (substr[i] == '.')
		i++;
	while (ft_isdigit((int) substr[i]))
		i++;
	if (substr[i] == convers)
		i++;
	if (len == i)
		return (1);
	else
		return (0);
}

static int	ft_printline(const char	*format, const char *flag, va_list args)
{
	char		*substr;
	t_strlen	str;
	t_struct	*data;

	substr = ft_substr(format, 0, flag - format + 1);
	if (!ft_checkformat(substr, *flag, flag - format + 1))
	{
		free(substr);
		return (0);
	}
	data = (t_struct *) malloc(sizeof(t_struct));
	if (!data)
		return (0);
	ft_initdata(data);
	ft_parse(data, substr, *flag);
	str = ft_finalstr(*flag, data, args);
	write(1, str.str, str.len);
	free(substr);
	free(data);
	free(str.str);
	return (str.len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			len++;
		}
		else
		{
			len += ft_printline(format, ft_pointerflag(format), args);
			format = ft_pointerflag(format);
		}
		if (*format)
			format++;
	}
	va_end(args);
	return (len);
}
