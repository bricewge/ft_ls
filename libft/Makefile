#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/01/21 14:00:10 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Disable implicit rules
.SUFFIXES:

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -Werror
## Flags for the C preprocessor
CPPFLAGS = -I$(INCLUDES)
NAME = libft.a

# Project related variables
SRC_PATH =  .
SRC_NAME =	ft_atoi.c		\
						ft_bzero.c	\
						ft_isalnum.c	\
						ft_isalpha.c	\
						ft_isascii.c	\
						ft_isdigit.c	\
						ft_islower.c	\
						ft_isprint.c	\
						ft_isspace.c	\
						ft_isupper.c	\
						ft_itoa.c	\
						ft_lstadd.c	\
						ft_lstdel.c	\
						ft_lstdelone.c	\
						ft_lstiter.c	\
						ft_lstmap.c	\
						ft_lstnew.c	\
						ft_memalloc.c	\
						ft_memccpy.c	\
						ft_memchr.c	\
						ft_memcmp.c	\
						ft_memcpy.c	\
						ft_memdel.c	\
						ft_memmove.c	\
						ft_memset.c	\
						ft_putchar.c	\
						ft_putchar_fd.c	\
						ft_putendl.c	\
						ft_putendl_fd.c	\
						ft_putnbr.c	\
						ft_putnbr_fd.c	\
						ft_putstr.c	\
						ft_putstr_fd.c	\
						ft_range.c	\
						ft_sqrt.c	\
						ft_strcat.c	\
						ft_strchr.c	\
						ft_strclr.c	\
						ft_strcmp.c	\
						ft_strcpy.c	\
						ft_strdel.c	\
						ft_strdup.c	\
						ft_strequ.c	\
						ft_striter.c	\
						ft_striteri.c	\
						ft_strjoin.c	\
						ft_strlcat.c	\
						ft_strlen.c	\
						ft_strmap.c	\
						ft_strmapi.c	\
						ft_strncat.c	\
						ft_strncmp.c	\
						ft_strncpy.c	\
						ft_strnequ.c	\
						ft_strnew.c	\
						ft_strnstr.c	\
						ft_strrchr.c	\
						ft_strsplit.c	\
						ft_strstr.c	\
						ft_strsub.c	\
						ft_strswap.c	\
						ft_strtrim.c	\
						ft_swap.c	\
						ft_tolower.c	\
						ft_toupper.c	\
						ft_strjoinf.c
OBJ_PATH =  obj
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INCLUDES = includes
HEADER = $(INCLUDES)/$(NAME:.a=.h)

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

.PHONY: clean
clean:
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) -r $(NAME) $(NAME).dSYM

re: fclean
	$(MAKE) all
