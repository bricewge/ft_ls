#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/02/05 12:54:43 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Disable implicit rules
.SUFFIXES:

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -Werror
## Flags for the C preprocessor
CPPFLAGS = -I$(INCLUDE) -I$(LIB)/$(INCLUDE)
## Libraries path
LDFLAGS = -L$(LIB)
## Libraries to link into the executable
LDLIBS = -lft
NAME = ft_ls

# Project related variables
SRC_PATH =  src
SRC_NAME =	usage.c			\
						file_mode.c	\
						error.c			\
						ft_ls.c
OBJ_PATH =  obj
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft
INCLUDE = include
HEADER = $(INCLUDE)/$(NAME).h

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(LIB)/$(LIB).a $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

list_dir: $(SRC_PATH)/list_dir.c $(SRC_PATH)/error.c $(HEADER) $(LIB)/$(LIB).a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(SRC_PATH)/list_dir.c $(SRC_PATH)/error.c $(LIB)/$(LIB).a -o list_dir

list_recur: $(SRC_PATH)/list_recur.c $(SRC_PATH)/file_mode.c  $(SRC_PATH)/error.c $(HEADER) $(LIB)/$(LIB).a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(SRC_PATH)/list_recur.c $(SRC_PATH)/file_mode.c $(SRC_PATH)/error.c $(LIB)/$(LIB).a -o list_recur

inspect_file: $(SRC_PATH)/inspect_file.c src/file_mode.c $(HEADER) $(LIB)/$(LIB).a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $< src/file_mode.c $(LIB)/$(LIB).a -o $@

test_opt: $(SRC_PATH)/test_opt.c $(SRC_PATH)/usage.c $(LIB)/ft_getopt.c $(HEADER) $(LIB)/$(LIB).a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(SRC_PATH)/test_opt.c $(SRC_PATH)/usage.c $(LIB)/ft_getopt.c $(LIB)/$(LIB).a -o $@


$(OBJ_PATH):
	mkdir $@

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# /!\ Dirty workaround /!\
# If make on the libft directory should rebuild something then PHONY the rule
# libft to build it. Otherwise it relink.
ifeq ($(shell $(MAKE) --question -C ./$(LIB) ; echo $$?), 1)
.PHONY: $(LIB)/$(LIB).a
endif

$(LIB)/$(LIB).a:
	$(MAKE) -C ./$(LIB)

.PHONY: clean
clean:
	$(MAKE) -C ./$(LIB) clean
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(MAKE) -C ./$(LIB) fclean
	$(RM) -r $(NAME) *.dSYM list_dir inspect_file

re: fclean
	$(MAKE) all
