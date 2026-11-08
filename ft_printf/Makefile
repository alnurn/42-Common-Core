# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 12:35:46 by anurmach          #+#    #+#              #
#    Updated: 2025/06/18 05:13:10 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror -I .
SRC_FOLDER = src
BONUS_FOLDER = bsrc
OBJ_FOLDER = obj

SRC =   src/ft_createaddr.c \
	src/ft_createint.c \
	src/ft_createu.c \
	src/ft_createx.c \
	src/ft_createxx.c \
	src/ft_finalstr.c \
	src/ft_isformatflag.c \
	src/ft_itoastrlen.c \
	src/ft_numlenu.c \
	src/ft_parse.c \
	src/ft_precision.c \
	src/ft_printf.c \
	src/ft_revstrcpy.c \
	src/ft_strwidth.c

BONUS_SRC =	bsrc/ft_createaddr_bonus.c \
		bsrc/ft_createint_bonus.c \
		bsrc/ft_createu_bonus.c \
		bsrc/ft_createx_bonus.c \
		bsrc/ft_createxx_bonus.c \
		bsrc/ft_finalstr_bonus.c \
		bsrc/ft_isformatflag_bonus.c \
		bsrc/ft_itoastrlen_bonus.c \
		bsrc/ft_numlenu_bonus.c \
		bsrc/ft_parse_bonus.c \
		bsrc/ft_precision_bonus.c \
		bsrc/ft_printf_bonus.c \
		bsrc/ft_revstrcpy_bonus.c \
		bsrc/ft_strwidth_bonus.c


OBJ = $(patsubst $(SRC_FOLDER)%.c, $(OBJ_FOLDER)%.o, $(SRC))
OBJ_BONUS = $(patsubst $(BONUS_FOLDER)%.c, $(OBJ_FOLDER)%.o, $(BONUS_SRC))

all : $(NAME)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ_FOLDER)/%.o : $(SRC_FOLDER)/%.c | $(OBJ_FOLDER)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_FOLDER)/%.o : $(BONUS_FOLDER)/%.c | $(OBJ_FOLDER)
	$(CC) $(CCFLAGS) -c $< -o $@

bonus : $(NAME) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ_FOLDER)

fclean : clean
	rm -f libft/libft.a
	rm -f $(NAME)
	
re : fclean all

.PHONY: all bonus clean fclean re
