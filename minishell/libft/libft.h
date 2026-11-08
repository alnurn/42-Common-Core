/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:16:18 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 16:39:48 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FDM
#  define FDM 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdarg.h>
# define HEX_BASE 16
# define DEC_BASE 10

typedef struct s_struct
{
	char	*remainder[FDM];
	int		start[FDM];
}	t_buffer;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

typedef struct s_truct
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

//------------   CHARS   ---------------//

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

void		ft_putchar_fd(char c, int fd);

//------------   STRINGS   -------------//

char		*ft_strchr(const char	*s, int c);
char		*ft_strdup(const char	*s);
size_t		ft_strlcat(char	*dst, const char	*src, size_t sz);
size_t		ft_strlcpy(char	*dst, const char	*src, size_t sz);
size_t		ft_strlen(const char	*s);
int			ft_strncmp(const char	*s1, const char	*s2, size_t n);
char		*ft_strnstr(const char	*haystack,
				const char	*needle, size_t len);
char		*ft_strrchr(const char	*s, int c);
char		*ft_substr(char const	*s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const	*s1, char const	*set);
char		**ft_split(char const	*s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void		ft_striteri(char	*s, void (*f)(unsigned int, char	*));
void		ft_putstr_fd(char	*s, int fd);
void		ft_putendl_fd(char	*s, int fd);

//------------   MEMORY   -------------//

void		ft_bzero(void	*s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void	*s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void	*dest, const void	*src, size_t n);
void		*ft_memset(void	*s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);

//------------   NUMBERS   -------------//

long		ft_atol(const char	*nptr);
int			ft_atoi(const char	*nptr);
void		ft_putnbr_fd(int nb, int fd);

//------------   LINKED LISTS   -------------//

t_list		*ft_lstnew(void	*content);
void		ft_lstadd_front(t_list	**lst, t_list	*new);
int			ft_lstsize(t_list	*lst);
t_list		*ft_lstlast(t_list	*lst);
void		ft_lstadd_back(t_list	**lst, t_list	*new);
void		ft_lstdelone(t_list	*lst, void (*del)(void	*));
void		ft_lstclear(t_list	**lst, void (*del)(void	*));
void		ft_lstiter(t_list	*lst, void (*f)(void	*));
t_list		*ft_lstmap(t_list	*lst, void	*(*f)(void	*),
				void (*del)(void *));

//------------   GET_NEXT_LINE   -------------//

char		*get_next_line(int fd);
void		ft_stringjoin(t_buffer	*buffer, char	*temp, int fd);
void		ft_clean(t_buffer	*buffer, char	*temp, int fd);
int			ft_findnl(t_buffer	*buffer, int bytes, int fd);
char		*ft_substring(t_buffer	*buffer, int end, int fd);

//------------   FT_PRINTF   -------------//

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
