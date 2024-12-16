# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 14:02:05 by edetoh            #+#    #+#              #
#    Updated: 2024/12/16 22:04:46 by edetoh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# =============================== VARIABLES =================================== #


NAME		= push_swap
INCLUDE		= include
LIBFT		= 42_libft-mylibft
SRC_DIR		= src/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm
AR			= ar rcs

# ================================ COULEURS =================================== #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
NC = \033[0m # No Color

# =============================== SOURCES ===================================== #

SRC_FILES	= commands/push \
			  procces/general_utils \
			  commands/rev_rotate \
			  commands/rotate \
			  commands/swap \
			  commands/sort_stacks \
			  commands/sort_three \
			  procces/handle_errors \
			  procces/init_a_to_b \
			  procces/init_b_to_a \
			  procces/stack_init \
			  procces/stack_utils \
			  push_swap \

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(SRC_DIR), $(addsuffix .o, $(SRC_FILES)))

# ============================== REGLES PRINCIPALES ========================== #

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "$(YELLOW)>>> Compilation de libft <<<$(DEF_COLOR)"
			make -C $(LIBFT)
			cp $(LIBFT)/libft.a .
			$(CC) $(CFLAGS) $(SRC) -o $(NAME) libft.a
			@echo "$(GREEN)>>> libftprintf.a créé avec succès <<<$(DEF_COLOR)"

# $(SRC_DIR)%.o: $(SRC_DIR)%.c
# 			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
# 			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


# ================================== CLEAN ==================================== #

clean:
			@echo "$(YELLOW)Cleaning object files...$(NC)"
			$(RM) -f $(OBJ)
			make clean -C $(LIBFT)
			$(RM) -f libft.a
			@echo "$(GREEN)Object files cleaned!$(NC)"

fclean:		clean
			@echo "$(YELLOW)Cleaning all files...$(NC)"
			$(RM) -f $(NAME)
			$(RM) -f libft.a
			$(RM) -f $(LIBFT)/libft.a
			@echo "$(GREEN)All files cleaned!$(NC)"

# ================================= REBUILD =================================== #

re:			fclean all
			@echo "$(GREEN)>>> Cleaned and rebuilt everything for ft_printf! <<<$(DEF_COLOR)"

# ================================ PHONY ====================================== #

.PHONY:		all clean fclean re
