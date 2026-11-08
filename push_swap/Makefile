# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 16:41:23 by anurmach          #+#    #+#              #
#    Updated: 2025/11/17 18:22:52 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BONUS := checker
CC := cc -Wall -Wextra -Werror
LIBFT := libft.a

SRC := ft_helpers.c \
	ft_swap.c \
	ft_rotate.c \
	ft_revrotate.c \
	ft_push.c \
	ft_generalsort.c \
	ft_twothreesort.c \
	ft_minmax.c \
	ft_indexcost.c \
	ft_findtarget.c \
	ft_findtargetback.c \
	ft_movetotop.c \
	ft_movetotopback.c \
	ft_makestacks.c \

PUSH_SWAP :=  $(SRC) push_swap.c
CHECKER :=  $(SRC) checker_bonus.c

all : $(NAME)
bonus : $(NAME_BONUS)

$(NAME) : $(LIBFT)
	$(CC) $(PUSH_SWAP) $(LIBFT) -o $@

$(NAME_BONUS) : $(LIBFT)
	$(CC) $(CHECKER) $(LIBFT) -o $@

$(LIBFT) : 
	$(MAKE) -C ./libft
	cp libft/$(LIBFT) .

clean:
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus