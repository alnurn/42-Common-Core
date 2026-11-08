# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#              #
#    Updated: 2026/10/03 15:29:23 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := src
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -f

SRCS := $(SRC)/megaphone.cpp

NAME := megaphone
OBJS := $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(SRC)/%.o : $(SRC)/%.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
