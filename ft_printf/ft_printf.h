/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:29:52 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 17:38:37 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"
# define HEX_BASE 16
# define DEC_BASE 10

typedef struct s_struct
{
	int	minus;
	int	zero;
	int	dot;
	int	sharp;
	int	space;
	int	plus;
	int	dot_precision;
	int	num_width;
}	t_struct;

typedef struct s_structure
{
	char	*str;
	int		len;
}	t_strlen;

int			ft_printf(const char *s, ...);
int			ft_isformatflag(char c);
int			ft_numlenu(unsigned int u, unsigned int base);
void		ft_parse(t_struct	*data, char	*substr, char convers);
void		ft_strwidth(t_strlen	*str, t_struct	*data, char c);
void		ft_revstrcpy(t_strlen	*str, int n, const char *src, char c);
void		ft_precision(t_strlen	*str, int len);
t_strlen	ft_createaddr(void	*ptr, t_struct	*data);
t_strlen	ft_createxx(unsigned int u, char convers);
t_strlen	ft_createx(unsigned int u, char convers, t_struct	*data);
t_strlen	ft_finalstr(char convers, t_struct	*data, va_list args);
t_strlen	ft_itoastrlen(int n);
t_strlen	ft_createint(int n, t_struct	*data);
t_strlen	ft_createu(unsigned int u, t_struct	*data);

#endif
