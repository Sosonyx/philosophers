# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 18:50:58 by ihadj             #+#    #+#              #
#    Updated: 2025/07/20 19:57:05 by ihadj            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ===========================[ Variables générales ]===========================

NAME        = philo
SRC_DIR     = srcs
BUILD_DIR   = build
INC         = includes
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -I$(INC)

SRC         = $(SRC_DIR)/main.c \
              $(SRC_DIR)/init/init.c \
              $(SRC_DIR)/parsing/parsing.c \
              $(SRC_DIR)/parsing/error.c \
              $(SRC_DIR)/routine/routine.c \
              $(SRC_DIR)/routine/routine2.c	\
              $(SRC_DIR)/routine/time.c \
              $(SRC_DIR)/monitoring/monitoring.c \
              $(SRC_DIR)/simulation/simulation.c \
              $(SRC_DIR)/exit/exit.c \
              $(SRC_DIR)/utils/utils.c \
			  $(SRC_DIR)/utils/color.c


OBJ         = $(addprefix $(BUILD_DIR)/, $(subst $(SRC_DIR)/,,$(SRC:.c=.o)))

# ================================[ Couleurs ]================================

GREEN       = \033[0;32m
RED         = \033[0;31m
BLUE        = \033[0;34m
BROWN       = \033[0;33m
BLUE        = \033[1;34m
END         = \033[0m
TITLE       = \033[1m

# ================================[ Règles Make ]==============================

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)🔘 $(TITLE)make $(NAME)$(END)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) > /dev/null && \
	echo "   $(GREEN)⤷ $(END)Executable: $(GREEN)$(NAME)$(END)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@if [ -z "$$(ls -A $(BUILD_DIR) 2>/dev/null)" ]; then \
		echo "$(GREEN)🔘 $(TITLE)Create object files$(END)"; fi
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null && \
	printf "   $(GREEN)⤷ $(BROWN)%-38s $(BLUE)⟹  $(BROWN)%s$(END)\n" "$<" "$@"

# ================================[ Nettoyage ]===============================

c clean:
	@echo "$(GREEN)🔘 $(TITLE)make clean$(END)"
	@rm -f $(OBJ) && echo "   $(GREEN)⤷ $(END)Removed object files"

fc fclean:
	@echo "$(GREEN)🔘 $(TITLE)make fclean$(END)"
	@if [ -f $(NAME) ]; then rm -f $(NAME) && echo "   $(GREEN)⤷ $(END)Removed binary $(NAME)"; fi
	@if [ -d $(BUILD_DIR) ]; then rm -rf $(BUILD_DIR) && echo "   $(GREEN)⤷ $(END)Removed build dir"; fi

re: fc all

.PHONY: all clean c fclean fc re
