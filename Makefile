# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 15:36:45 by ihadj             #+#    #+#              #
#    Updated: 2025/07/10 17:12:02 by ihadj            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

# Directories
SRCS_DIR    = srcs
INCLUDES_DIR= includes
LIBFT_DIR   = libft

# Compiler
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -I$(INCLUDES_DIR) -I$(LIBFT_DIR)

# Libraries
LIBFT_A     = $(LIBFT_DIR)/libft.a
PRINTF_DIR  = libft/printf
PRINTF_A    = $(PRINTF_DIR)/libftprintf.a

SRCS = 	$(SRCS_DIR)/utils/utils.c \
	$(SRCS_DIR)/init/init.c \
	$(SRCS_DIR)/main.c

OBJS = $(SRCS:.c=.o)

# Main rule
all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_A)

# Compil rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Librairies rules
$(PRINTF_A):
	make -C $(PRINTF_DIR)
$(LIBFT_A):
	make -C $(LIBFT_DIR)

# Cleaning rules
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re