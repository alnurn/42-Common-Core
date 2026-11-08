# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#              #
#    Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := src
HEADERS := headers
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP -I $(HEADERS)
RM := rm -f

SRCS := $(SRC)/main.cpp \
		$(SRC)/Animal.cpp \
		$(SRC)/Dog.cpp \
		$(SRC)/Cat.cpp \
		$(SRC)/WrongAnimal.cpp \
		$(SRC)/WrongCat.cpp \
		$(SRC)/Brain.cpp

NAME := brain
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
