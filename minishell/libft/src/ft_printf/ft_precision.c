/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:16:15 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 13:16:49 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_precision(t_strlen	*str, int len)
{
	char		*temp;

	temp = str->str;
	str->str = (char *) malloc((len + 1) * sizeof(char));
	if (!str->str)
	{
		str->len = 0;
		return ;
	}
	str->str[len] = '\0';
	ft_revstrcpy(str, len, (const char *) temp, '0');
	free(temp);
	str->len = len;
}
