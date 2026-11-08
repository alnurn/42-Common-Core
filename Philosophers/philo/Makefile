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
CFLAGS := -Wall -Wextra -Werror -pthread -I $(HEADERS)
RM := rm -f

SRCS := $(SRC)/philo.c \
		$(SRC)/philo_utils.c \
		$(SRC)/atoull.c \
		$(SRC)/parsearg.c \
		$(SRC)/sim.c \
		$(SRC)/mutexes.c \
		$(SRC)/pthreads.c \
		$(SRC)/track.c \
		$(SRC)/eat_utils.c \
		$(SRC)/routine.c

PHILO := philo
OBJS := $(SRCS:.c=.o)

all : $(PHILO)

$(PHILO) : $(OBJS)
		$(CC) $(OBJS) -o $@

$(SRC)/%.o : $(SRC)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(PHILO)

re: fclean all

.PHONY: all clean fclean re

# valgrind --tool=helgrind ./philo 5 800 200 200
# valgrind --tool=helgrind --history-level=full --track-lockorders=yes ./philo 5 800 200 200
# valgrind --tool=helgrind --history-level=full --track-lockorders=yes --check-stack-refs=yes --fair-sched=yes ./philo 5 800 200 200 4
# valgrind --tool=drd ./philo 5 800 200 200 3
