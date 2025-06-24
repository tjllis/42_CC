# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 13:46:05 by tsemenov          #+#    #+#              #
#    Updated: 2025/05/11 13:46:06 by tsemenov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDES = includes/

SRC_FILES =\
		error_clean.c \
		helpers.c \
		ft_split.c \
		parsing_str.c \
		parsing_mult.c \
		parsing_utils.c \
		push_swap.c \
		normalize_values.c \
		radix_sort.c \
		rev_rotations.c \
		rotations.c \
		small_sort.c \
		stack_ops.c \
		stack_utils.c \
		swaps_pushes.c \
		validation.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

OBJ_FLAG = .cache_exists

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_FLAG)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FLAG):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJ_FLAG)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
