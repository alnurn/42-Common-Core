# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#              #
#    Updated: 2026/02/14 15:55:26 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := src
HEADERS := headers

CC := cc
CFLAGS := -Wall -Wextra -Werror -g -pthread -I $(HEADERS)
RM := rm -f

SRCS := $(SRC)/philo_bonus.c \
		$(SRC)/parsearg_bonus.c \
		$(SRC)/print_utils_bonus.c \
		$(SRC)/sim_bonus.c \
		$(SRC)/semaphores_bonus.c \
		$(SRC)/time_utils_bonus.c \
		$(SRC)/exit_utils_bonus.c \
		$(SRC)/init_philo_bonus.c \
		$(SRC)/philo_routine_utils_bonus.c \
		$(SRC)/monitor_bonus.c \

PHILO := philo_bonus
OBJS := $(SRCS:.c=.o)

bonus : $(PHILO)

$(PHILO) : $(OBJS)
		$(CC) $(OBJS) -o $@

$(SRC)/%.o : $(SRC)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(PHILO)

re: fclean bonus

.PHONY: bonus clean fclean re

# valgrind --tool=helgrind ./philo 5 800 200 200
# valgrind --tool=helgrind --history-level=full --track-lockorders=yes ./philo 5 800 200 200
# valgrind --tool=helgrind --history-level=full --track-lockorders=yes --check-stack-refs=yes --fair-sched=yes ./philo 5 800 200 200 4
# valgrind --tool=drd ./philo 5 800 200 200 3
