NAME = minitalk
SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_SERVER = server.c
SRC_CLIENT = client.c client_utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

PID ?=
MSG ?=

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT): $(LIBFT_DIR)
	@make -C$(LIBFT_DIR);
	@echo "Built: libft"

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -L$(LIBFT_DIR) -lft -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -L$(LIBFT_DIR) -lft -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

vg_server: $(SERVER)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(SERVER)

vg_client: $(CLIENT)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(CLIENT) $(PID) $(MSG)

clean:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@if [ -f $(LIBFT_DIR)/Makefile ]; then make -C $(LIBFT_DIR) clean 2>/dev/null || true; fi

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@if [ -f $(LIBFT_DIR)/Makefile ]; then \
		make -C $(LIBFT_DIR) fclean 2>/dev/null || \
		make -C $(LIBFT_DIR) clean 2>/dev/null || true; \
	fi

re: fclean all

.PHONY: all clean fclean re vg_server vg_client
