# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 23:43:33 by anurmach          #+#    #+#              #
#    Updated: 2025/05/26 02:07:44 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc -Wall -Wextra -Werror
OBJ_FOLDER = objs
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRC_BONUS = $(wildcard ft_lst*.c)
OBJ = $(patsubst %.c, ./$(OBJ_FOLDER)/%.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, ./$(OBJ_FOLDER)/%.o, $(SRC_BONUS))

all : $(NAME)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER) 
$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
bonus : $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)
./$(OBJ_FOLDER)/%.o : %.c | $(OBJ_FOLDER)
	$(CC) -c $< -o $@
clean :
	rm -rf $(OBJ_FOLDER)
fclean : clean
	rm -f $(NAME)
re : fclean all
