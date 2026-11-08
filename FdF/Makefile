# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#              #
#    Updated: 2026/02/14 15:55:26 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := src
HEADERS := headers
LIBFT_DIR := libft
MLX_DIR := minilibx-linux

LIBFT := $(LIBFT_DIR)/libft.a
MLX := $(MLX_DIR)/libmlx.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -I $(HEADERS) -I $(MLX_DIR)
LDFLAGS := -L $(LIBFT_DIR) -L $(MLX_DIR)
LDLIBS := -lft -lmlx -lm -lXext -lX11
RM := rm -f


SRCS := $(SRC)/fdf.c \
		$(SRC)/ft_color.c \
		$(SRC)/ft_draw.c \
		$(SRC)/ft_events.c \
		$(SRC)/ft_extractcolor.c \
		$(SRC)/ft_helpers_extra.c \
		$(SRC)/ft_helpers.c \
		$(SRC)/ft_initmap.c \
		$(SRC)/ft_mouse_events_extra.c \
		$(SRC)/ft_mouse_events.c \
		$(SRC)/ft_projections.c \
		$(SRC)/ft_render.c \
		$(SRC)/ft_rotate.c \
		$(SRC)/ft_transform.c

FDF := fdf
OBJS := $(SRCS:.c=.o)

all : $(FDF)
bonus : all

$(FDF) : $(OBJS) $(LIBFT) $(MLX)
		$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)
$(MLX):
		$(MAKE) -C $(MLX_DIR)

$(SRC)/%.o : $(SRC)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(MLX_DIR) clean

fclean: clean
		$(RM) $(FDF)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
