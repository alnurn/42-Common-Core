# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 23:43:33 by anurmach          #+#    #+#              #
#    Updated: 2025/11/17 16:38:15 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc -Wall -Wextra -Werror -I .

SRC =	src/libft/ft_atol.c \
	src/libft/ft_atoi.c \
	src/libft/ft_bzero.c \
	src/libft/ft_calloc.c \
	src/libft/ft_isalnum.c \
	src/libft/ft_isalpha.c \
	src/libft/ft_isascii.c \
	src/libft/ft_isdigit.c \
	src/libft/ft_isprint.c \
	src/libft/ft_itoa.c \
	src/libft/ft_memchr.c \
	src/libft/ft_memcmp.c \
	src/libft/ft_memcpy.c \
	src/libft/ft_memmove.c \
	src/libft/ft_memset.c \
	src/libft/ft_putchar_fd.c \
	src/libft/ft_putendl_fd.c \
	src/libft/ft_putnbr_fd.c \
	src/libft/ft_putstr_fd.c \
	src/libft/ft_split.c \
	src/libft/ft_strchr.c \
	src/libft/ft_strdup.c \
	src/libft/ft_striteri.c \
	src/libft/ft_strjoin.c \
	src/libft/ft_strlcat.c \
	src/libft/ft_strlcpy.c \
	src/libft/ft_strlen.c \
	src/libft/ft_strmapi.c \
	src/libft/ft_strncmp.c \
	src/libft/ft_strnstr.c \
	src/libft/ft_strrchr.c \
	src/libft/ft_strtrim.c \
	src/libft/ft_substr.c \
	src/libft/ft_tolower.c \
	src/libft/ft_toupper.c \
	src/libft/ft_lstnew.c \
	src/libft/ft_lstlast.c \
	src/libft/ft_lstadd_back.c \
	src/libft/ft_lstadd_front.c \
	src/libft/ft_lstclear.c \
	src/libft/ft_lstdelone.c \
	src/libft/ft_lstsize.c \
	src/get_next_line/get_next_line.c \
	src/get_next_line/get_next_line_utils.c \
	src/ft_printf/ft_createaddr.c \
	src/ft_printf/ft_createint.c \
	src/ft_printf/ft_createu.c \
	src/ft_printf/ft_createx.c \
	src/ft_printf/ft_createxx.c \
	src/ft_printf/ft_finalstr.c \
	src/ft_printf/ft_isformatflag.c \
	src/ft_printf/ft_itoastrlen.c \
	src/ft_printf/ft_numlenu.c \
	src/ft_printf/ft_parse.c \
	src/ft_printf/ft_precision.c \
	src/ft_printf/ft_printf.c \
	src/ft_printf/ft_revstrcpy.c \
	src/ft_printf/ft_strwidth.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
%.o : %.c
	$(CC) -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re