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

NAME_SERVER := server
NAME_SERVER_BONUS := server_bonus
NAME_CLIENT := client
NAME_CLIENT_BONUS := client_bonus
CC := cc -Wall -Wextra -Werror
LIBFT := libft.a

SERVER := server.c
CLIENT := client.c
SERVER_BONUS := server_bonus.c
CLIENT_BONUS := client_bonus.c

all : $(NAME_SERVER) $(NAME_CLIENT)
bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER) : $(LIBFT)
	$(CC) $(SERVER) $(LIBFT) -o $@

$(NAME_CLIENT) : $(LIBFT)
	$(CC) $(CLIENT) $(LIBFT) -o $@

$(NAME_SERVER_BONUS) : $(LIBFT)
	$(CC) $(SERVER_BONUS) $(LIBFT) -o $@

$(NAME_CLIENT_BONUS) : $(LIBFT)
	$(CC) $(CLIENT_BONUS) $(LIBFT) -o $@

$(LIBFT) : 
	$(MAKE) -C ./libft
	cp libft/$(LIBFT) .

clean:
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER_BONUS)
	rm -f $(NAME_CLIENT_BONUS)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus