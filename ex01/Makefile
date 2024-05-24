# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 22:14:04 by amak              #+#    #+#              #
#    Updated: 2024/05/24 23:11:54 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = TowardsAMoreUsefulFixedpointNumberClass

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = 	Fixed.cpp \
			main.cpp
			
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)
	
$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	
clean:
	@rm -f $(OBJECTS)
	@echo Deleted object files!

fclean: clean
	@rm -f $(NAME)
	@echo Deleted executable!

re: fclean all

.PHONY: all bonus clean fclean re
