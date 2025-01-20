# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 11:04:42 by msalembe          #+#    #+#              #
#    Updated: 2025/01/20 11:27:53 by msalembe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = validator

SRC = main.c extra.c func.c utils.c gnl/get_next_line.c gnl/get_next_line_utils.c


OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "libft compiled"

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "validator compiled"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@echo "validator objects removed"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "validator removed"

re: fclean all

.PHONY: all clean fclean re
