/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:30:13 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 18:30:16 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>

typedef struct s_line
{
	int			n;
	int			flag;
	uint32_t	len;
	char		*str;
}	t_line;

typedef struct s_encode
{
	unsigned char	bit;
	int				byte;
	int				i;
}	t_encode;

#endif