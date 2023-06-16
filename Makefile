# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 11:27:45 by jflorido          #+#    #+#              #
#    Updated: 2023/04/23 12:23:41 by arlo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

define HEADER

  _____         _
 / ____|       | |
| (___   ___   | |     ___  _ __   __ _
 \___ \ / _ \  | |    / _ \| '_ \ / _` |
 ____) | (_) | | |___| (_) | | | | (_| |
|_____/ \___/  |______\___/|_| |_|\__, |
                                   __/ |
                                  |___/

       _                                                      ___       ___
  o  _|_  |   _   ._  o   _|   _      /     /\   ._  |    _    |    _    |       | |
  |   |   |  (_)  |   |  (_|  (_)    /     /--\  |   |_  (_)   |   (/_   |   ><  |_|
 _|

endef
export HEADER

# Folders
SRC_DIR = src/
OBJ_DIR = obj/

OBJF = obj
INC = inc

# Files
SRC_FILES = so_long sl_utils sl_checks_util sl_checks_util_2 \
				sl_exit sl_place_textures sl_movements
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#Commands
CC 			= 	gcc
#CFLAGS 		= 	-Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS 		= 	-Wall -Wextra -Werror -g3
RM 			= 	rm -rf
MLX			=	-Lmlx -lmlx -framework OpenGL -framework AppKit

#SRC 		=	main.c

LIBFT_a 	= 	libft/libft.a
GNL_a		=	Get_Next_line/ft_gnl.a
FT_PRINTF_a	=	ft_printf/libftprintf.a
MLX_a		=	mlx/libmlx.a

#OBJS 		= 	$(SRC:.c=.o)

#Colors:

DEF_COLOR 	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;31m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# ====================================================================== #

all: $(NAME)

# Compiling all
$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./Get_Next_line
	@$(MAKE) -C ./ft_printf
	@$(MAKE) -C ./mlx
	@$(CC) $(CFLAGS) $(OBJS) -I $(INC) $(LIBFT_a) $(GNL_a) $(FT_PRINTF_a) $(MLX_a) $(MLX) -o $(NAME)
	@echo "$(GREEN)$$HEADER$(DEF_COLOR)"
	@echo "$(GREEN)So_Long compiled!$(DEF_COLOR)"

# Compiling individual
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(BLUE)Compiling $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -Imlx -I $(INC) -c $< -o $@

# Crear directorio temporal para los obj
$(OBJF):
	@mkdir -p $(OBJ_DIR)

# Cleanning files
clean:
	$(RM) $(OBJS)
	@make clean -C ./libft
	@make clean -C ./Get_Next_line
	@make clean -C ./mlx
	@echo "$(YELLOW)&(OBJS) --> Files removed.$(DEF_COLOR)"

#Cleanning files and executable
fclean: clean
	$(RM) $(NAME)
	@MAKE fclean -C ./libft
	@MAKE fclean -C ./Get_Next_line
	#@MAKE fclean -C ./mlx
	@echo "$(RED)$(NAME) Executable files removed!$(DEF_COLOR)"

re: fclean all

norm:
	@norminette $(SRC_DIR) $(INC)

.PHONY: all clean fclean re