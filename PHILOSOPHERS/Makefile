NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0 -pthread
LDFLAGS = -lpthread

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDES = -I./includes

SRC_FILES =\
				cleaners.c \
				ft_eat.c \
				getters.c \
				setters.c \
				init_data.c \
				init_philos.c \
				m_routine.c \
				parsing.c \
				ph_routine.c \
				main.c \
				simulation.c \
				utils.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

OBJ_FLAG = .cache_exists

all: $(NAME)

$(OBJ_DIR):
	@mkdir obj

$(OBJ_FLAG):
	@touch $(OBJ_FLAG)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_FLAG)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "Simulation: ready"

vg: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-children=yes ./$(NAME) $(ARGS)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJ_FLAG)
	@echo "Simulation: clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "Simulation: fclean done"

re: fclean all

.PHONY: all clean fclean re
