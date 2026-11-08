# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#              #
#    Updated: 2026/10/16 16:45:16 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := src
HEADERS := headers
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP -I $(HEADERS)
RM := rm -f

SRCS := $(SRC)/main.cpp \
		$(SRC)/Zombie.cpp \
		$(SRC)/newZombie.cpp \
		$(SRC)/randomChump.cpp

NAME := zombie
OBJS := $(SRCS:.cpp=.o)
DEP := $(OBJS:.o=.d)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(SRC)/%.o : $(SRC)/%.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
		$(RM) $(OBJS) $(DEP)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
