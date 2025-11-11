# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 14:00:54 by tomas             #+#    #+#              #
#    Updated: 2025/11/11 11:57:39 by toandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -I./libft

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Emojis
COMPILE_EMOJI = 🔨
LIBRARY_EMOJI = 📚
CLEAN_EMOJI = 🧹
SUCCESS_EMOJI = ✅
ROCKET_EMOJI = 🚀
GAME_EMOJI = 🎮

# Source files
SRCS = src/map_parser.c \
       src/map_validation.c \
       src/map_helpers.c \
       src/utils.c \
			 src/pathfinding.c \
			 src/main.c \
			 src/controls.c \
			 src/render.c \
			 src/game_init.c

# Object files
OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))

# Libraries
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# MLX
 MLX_DIR = minilibx-linux
 MLX = $(MLX_DIR)/libmlx.a
 MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS)
	@echo "$(GAME_EMOJI) $(CYAN)Creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(SUCCESS_EMOJI) $(GREEN)$(NAME) created successfully!$(RESET)"

# Create objects directory
$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

# Compilation rule for src directory
$(OBJSDIR)/%.o: src/%.c | $(OBJSDIR)
	@echo "$(COMPILE_EMOJI) $(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT):
	@echo "$(LIBRARY_EMOJI) $(BLUE)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(SUCCESS_EMOJI) $(GREEN)Libft built successfully!$(RESET)"

# Build MLX
$(MLX):
	@echo "$(LIBRARY_EMOJI) $(BLUE)Building MiniLibX...$(RESET)"
	@make -C $(MLX_DIR)
	@echo "$(SUCCESS_EMOJI) $(GREEN)MiniLibX built successfully!$(RESET)"

clean:
	@echo "$(CLEAN_EMOJI) $(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJSDIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "$(SUCCESS_EMOJI) $(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(CLEAN_EMOJI) $(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(SUCCESS_EMOJI) $(GREEN)$(NAME) removed!$(RESET)"

re: fclean all
	@echo "$(ROCKET_EMOJI) $(PURPLE)Rebuild complete!$(RESET)"

.PHONY: all clean fclean re