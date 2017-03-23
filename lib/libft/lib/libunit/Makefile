# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: starrit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 11:30:09 by starrit           #+#    #+#              #
#    Updated: 2017/02/12 13:49:18 by starrit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Disable implicit rules
.SUFFIXES:

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -Werror
## Flags for the C preprocessor
CPPFLAGS = -I$(INCLUDE) 
NAME = libunit.a

# Project related variables
SRC_PATH = src
SRC_NAME =	add_test_lst.c				\
						create_test_lst.c			\
						del_test_lst.c				\
						load_test.c						\
						launch_test.c					\
						print_header.c				\
						print_total.c					\
						string.c							\
						print.c
OBJ_PATH =  obj
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INCLUDE = include
HEADER = $(INCLUDE)/$(NAME:.a=.h)

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH):
	mkdir $@

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

test: $(NAME)
	$(MAKE) -C tests test

.PHONY: clean
clean:
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) -r $(NAME) $(NAME).dSYM

re: fclean
	$(MAKE) all
