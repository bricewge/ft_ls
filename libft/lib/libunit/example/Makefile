#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/02/11 23:31:47 by starrit          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Disable implicit rules
.SUFFIXES:

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -Werror
## Flags for the C preprocessor
CPPFLAGS = -I. -I$(LIB_PATH)/$(INCLUDE)/ -I../$(INCLUDE)/
## Libraries path
LDFLAGS = -L$(LIB_PATH)/ -L..
## Libraries to link into the executable
LDLIBS = -l$(LIB) -lft
NAME = tests

# Project related variables
SRC_PATH = .
SRC_NAME =	main.c						\
		stdlib/ft_atoi/00_launcher.c				\
		stdlib/ft_atoi/01_basic_negative_test.c		\
		stdlib/ft_atoi/02_basic_positive_test.c		\
		stdlib/ft_atoi/03_basic_jump_test.c			\
		stdlib/ft_atoi/04_null_test.c				\
		stdlib/ft_atoi/05_error_test.c				\
		stdlib/ft_atoi/06_error_stop_test.c			\
		stdlib/ft_atoi/07_error_signe_test.c			\
		stdlib/ft_atoi/08_intmin_test.c			\
		stdlib/ft_atoi/09_intmax_test.c			\
		stdlib/ft_atoi/10_small_negative_loop_test.c		\
		stdlib/ft_atoi/11_small_positive_loop_test.c		\
		stdlib/ft_atoi/12_medium_negative_loop_test.c		\
		stdlib/ft_atoi/13_medium_positive_loop_test.c		\
		stdlib/ft_atoi/14_large_negative_loop_test.c		\
		stdlib/ft_atoi/15_large_positive_loop_test.c
OBJ_PATH =  obj
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = unit
LIB_PATH = ../lib/libunit
LIB_NAME = libunit
INCLUDE = include
HEADER = ../$(LIB_PATH)/$(INCLUDE)/$(LIB_NAME).h

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(LIB_PATH)/$(LIB_NAME).a  ../libft.a $(SRC) tests.h
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(SRC) -o $(NAME)

$(OBJ_PATH):
	mkdir $@

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# /!\ Dirty workaround /!\
# If make on the libft directory should rebuild something then PHONY the rule
# libft to build it. Otherwise it relink.
ifeq ($(shell $(MAKE) --question -C $(LIB_PATH) ; echo $$?), 1)
.PHONY: $(LIB_PATH)/$(LIB_NAME).a
endif

$(LIB_PATH)/$(LIB_NAME).a:
	$(MAKE) -C $(LIB_PATH)

ifeq ($(shell $(MAKE) --question -C .. ; echo $$?), 1)
.PHONY: ../libft.a
endif

../libft.a:
	$(MAKE) -C ..

test: $(NAME)
	./$(NAME)

.PHONY: clean
clean:
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) -r $(NAME) *.dSYM

re: fclean
	$(MAKE) all
