# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 14:48:39 by ihadj             #+#    #+#              #
#    Updated: 2025/06/12 13:52:22 by ihadj            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRCS =  ft_strncmp.c ft_strlen.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
        ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c  \
        ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
        ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		printf/ft_printf.c printf/ft_printf_checking.c  printf/ft_printf_printinghexa.c \
		printf/ft_printf_printingint.c printf/ft_printf_printingchar.c \
		GNL/get_next_line.c GNL/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
			 ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

